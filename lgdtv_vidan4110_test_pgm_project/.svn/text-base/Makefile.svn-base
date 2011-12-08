NAME = vidan4110_test_pgm
DEPEND = depend

CC = gcc
LD = gcc

LIBDIR=lib
INCLUDEDIR=include

OBJDIR = obj
BINDIR = bin

INCFLAGS=
CFLAGS= -Wall -g -O2
#LDFLAGS= -L${LIBDIR} -lvidan4110 -lusb-1.0 -lpthread -lrt
LDFLAGS= -L${LIBDIR} -lvidan4110 -lusb-1.0 -lpthread

BIN= $(BINDIR)/$(NAME)

################################################################
# Sample App                                                   #
################################################################
INCFLAGS= -I$(INCLUDEDIR)
SRCDIR= src

CSRC= $(wildcard $(SRCDIR)/*.c)

GLOBAL_OBJ = \
				 $(CSRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)


OBJ= $(GLOBAL_OBJ)

#default: bin tags
default: bin

tags:
	@echo update tag Tagle
	@ctags -R


bin: $(BIN)

$(BIN): $(OBJ) lib/libvidan4110.a
	@echo
	@echo 'creating binary "$(BIN)"'
	@$(LD) $(OBJ) $(LDFLAGS) -o $(BIN) 

depend:
	@echo
	@echo 'Checking Dependencies'
	@$(SHELL) -ec 'gcc -MM -D__MSDOS__ \
						$(INCFLAGS) \
						$(CSRC) \
						| sed '\''s@\(.*\)\.o[ :]@$(OBJDIR)/\1.o:@g'\'' \
						'>>$(DEPEND)
	@echo


################################################################
# Global                                                       #
################################################################
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo 'compiling object file "$<" ...'
	@$(CC) -c -o $@ $(INCFLAGS) $(CFLAGS) $<


clean:
	@echo remove all objects
	rm -f $(OBJDIR)/*.o
	rm -f $(BIN)
	rm -f tags









