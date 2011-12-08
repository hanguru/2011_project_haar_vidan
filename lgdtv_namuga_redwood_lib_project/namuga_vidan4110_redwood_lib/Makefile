NAME = libvidan4110.a

DEPEND = depend


CC = gcc
AR = ar

TARGETDIR = target
OBJDIR = obj
TARGETLIBDIR = $(TARGETDIR)/lib
TARGETINCDIR = $(TARGETDIR)/include

INCFLAGS =
CFLAGS = -Wall -g -O3
ARFLAGS = rcs

TARGETLIB = $(TARGETLIBDIR)/$(NAME)

################################################################
# Redwood Lib                                                  #
################################################################
LIBUSB_INCDIR=include/libusb-1.0
REDWOOD_SRCDIR=redwood_lib_src/src
REDWOOD_INCDIR=redwood_lib_src/include
REDWOOD_HEADER=redwood_api.h

REDWOOD_INCFLAGS= -I$(REDWOOD_INCDIR)
REDWOOD_INCFLAGS+= -I${LIBUSB_INCDIR}

REDWOOD_CSRC= $(wildcard $(REDWOOD_SRCDIR)/*.c)

REDWOOD_OBJ = \
				 $(REDWOOD_CSRC:$(REDWOOD_SRCDIR)/%.c=$(OBJDIR)/%.o)


OBJ= $(REDWOOD_OBJ) 

default: lib cplib
#default: lib

MAINAPPDIR = ../../lgdtv_vidan4110_test_pgm_project
MAINAPPLIBDIR = $(MAINAPPDIR)/lib
MAINAPPINCDIR = $(MAINAPPDIR)/include

cplib:
	@echo
	@echo 'copy "$(TARGETLIB)" to main application'
	@cp -f $(TARGETLIB) $(MAINAPPLIBDIR)
	@echo 'copy "$(TARGETINCDIR)/$(REDWOOD_HEADER)" to main application'
	@cp -f $(TARGETINCDIR)/$(REDWOOD_HEADER) $(MAINAPPINCDIR)

tags:
	@echo update tag Tagle
	@ctags -R


lib: $(TARGETLIB)

$(TARGETLIB): $(OBJ)
	@echo
	@echo 'creating library "$(TARGETLIB)"'
	@$(AR) $(ARFLAGS) $(TARGETLIB) $(OBJ)
	@echo 'copy header file $(REDWOOD_INCDIR)/$(REDWOOD_HEADER)'
	@cp $(REDWOOD_INCDIR)/$(REDWOOD_HEADER) $(TARGETINCDIR)


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
# Redwood                                                      #
################################################################
$(OBJDIR)/%.o: $(REDWOOD_SRCDIR)/%.c
	@echo 'compiling object file "$<" ...'
	@$(CC) -c -o $@ $(REDWOOD_INCFLAGS) $(CFLAGS) $<


clean:
	@echo remove all objects
	rm -f $(OBJDIR)/*.o
	rm -f $(TARGETLIB)
	rm -f $(TARGETINCDIR)/$(REDWOOD_HEADER)
	rm -f tags









