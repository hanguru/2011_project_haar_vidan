#!/usr/bin/perl
#-------------------------------------------------------------------------------
# 
# Title      : Binary to Text Converter
# Filename   : bin2txt.pl
# Author     : Jae-Sun Kim (milko@capp.snu.ac.kr)
# adjustment : Cho Myung je(luslas@gmail.com)
# Date       : 2004. 1. 1
#
#-------------------------------------------------------------------------------
# Usage: bin2txt.pl [OPTION]... SOURCE DEST
# Convert SOURCE to DEST
# 
#   -r            reverse (text to binary)
#   -s <size>     unit size: 8, 16, [32]
#   -x <radix>    radix: 10, [16]
#   -h <header>   header string of each line
#   -f <footer>   footer string of each line
# 
# Report bugs to <luslas@gmail.com>
#-------------------------------------------------------------------------------

use strict;

# options
my ($ifile, $ofile);
my $reverse = 0;
my $size = 32;
my $radix = 16;
my $endian= 1; # 1 is big endian, 0 is little endian.
my ($header, $footer);

# parse options
while (@ARGV) {
   my $opt = shift @ARGV;
   if ($opt eq "-r") {
      $reverse = 1;
   } elsif ($opt eq "-s") {
      print_usage() unless @ARGV;
      $size = shift @ARGV;
   } elsif ($opt eq "-x") {
      print_usage() unless @ARGV;
      $radix = shift @ARGV;
   } elsif ($opt eq "-h") {
      print_usage() unless @ARGV;
      $header = shift @ARGV;
   } elsif ($opt eq "-f") {
      print_usage() unless @ARGV;
      $footer = shift @ARGV;
   } elsif ($opt eq "-l") {
      $endian= 0;
   } elsif (!defined $ifile) {
      $ifile = $opt;
   } elsif (!defined $ofile) {
      $ofile = $opt;
   } else {
      print_usage();
   }
}
print_usage() unless (defined $ifile && defined $ofile);

open IFILE, "$ifile" or die $!;
open OFILE, ">$ofile" or die $!;

if ($reverse) { txt2bin(); }
else { bin2txt(); }

close IFILE;
close OFILE;

#------------------------------ END OF MAIN ------------------------------#


# functions
sub print_usage {
   $0 =~ s#.*/##;
   print "Usage: $0 [OPTION]... SOURCE DEST
Convert SOURCE to DEST

   -r            reverse (text to binary)
   -s <size>     unit size: 8, 16, [32]
   -x <radix>    radix: 2, 10, [16]
   -h <header>   header string of each line
   -f <footer>   footer string of each line
   -l <endian>   It's little endian.(difalut setting is big endian.
                 ex) 
                     |=====================================|
                     |hex data : 00010203                  |
                     |=====================================|
                     |address | little endian | big endian |
                     |-------------------------------------|
                     |   00   |       00      |     03     |
                     |   01   |       01      |     02     |
                     |   10   |       02      |     01     |
                     |   11   |       03      |     00     |
                     |=====================================|

Report bugs to <luslas\@capp.snu.ac.kr>.
";
   exit;
}

# binary to text
sub bin2txt {
   my ($buf, $n);
   my %template = ( 8 => "C", 16 => "n", 32 => "N" );
   my $format = "%0";

   if ($radix == 2) { $format .= $size."b"; }
   elsif ($radix == 10) { $format .= "d"; }
   else { $format .= ($size / 4)."x"; }
	#else { $format .= ($size / 4)."x"; }

   until (eof IFILE) {
      read IFILE, $buf, ($size / 8);
      ($n) = unpack($template{$size}, $buf);

      if ($endian == 1){
         if ($size == 8) {
            ($n) = ($n & 0xff);
         } elsif ($size == 16) {
            ($n) = (($n >> 8) & 0xff | ($n << 8) & 0xff00);
         } else {
            ($n) = ($n >> 24) & 0xff | ($n >> 8) & 0xff00 | ($n << 8) & 0xff0000 | ($n << 24) & 0xff000000;
         }
      }

      printf OFILE "$header$format$footer\n", $n;
   }
}

# text to binary
sub txt2bin {
   my $n;

   while (<IFILE>) {
      chomp;
      s/^\Q$header\E//;
      s/\Q$footer\E$//;

      if ($radix == 2) { $n = oct("b".$_); }
      elsif ($radix == 10) { $n = $_; }
      else { $n = hex($_); }

      if ($size == 8) {
         printf OFILE "%c", $n & 0xff;
      } elsif ($size == 16) {
         if ($endian == 1) {
            printf OFILE "%c"x2, $n & 0xff , ($n >> 8) & 0xff;
         } else {
            printf OFILE "%c"x2, ($n >> 8) , 0xff & $n & 0xff;
         }
      } else {
         if ($endian == 1){
            printf OFILE "%c"x4, $n & 0xff, ($n >> 8) & 0xff, ($n >> 16) & 0xff, ($n >> 24) & 0xff;
         } else {
            printf OFILE "%c"x4, ($n >> 24) & 0xff, ($n >> 16) & 0xff, ($n >> 8) & 0xff, $n & 0xff;
         }
      }
   }
}
