# Makefile template file for FLAME
#
# FLAME is the FLAME source files
# SOURCE is the user source files
#
# The assumption is that the user only provides C files
# and a model files <file>.xml
#
PGPLOT_DIR    = /usr/local/pgplot
X11_DIR	      =/usr/X11R6/lib

DEFINES		=

#DEFINES	+= -DSTART_END 
#DEFINES	+= -DGRAPHICS

LIBMBOARD_DIR = /home/cg/SANDBOX/xagents/libmboard
#LIBMBOARD_DIR = /cygdrive/c/cg44/SANDBOX/libmboard/build
LIBMBOARD_INC = $(LIBMBOARD_DIR)/include
LIBMBOARD_LIB = $(LIBMBOARD_DIR)/lib

INCLUDES = /usr/local/pgplot

CC      = gcc
CFLAGS  = -std=c99 -Wall -I$(INCLUDES) -I$(LIBMBOARD_INC) ${DEFINES}
CF      = gfortran 
#CF      = g95 

CFLAGS += -D_DEBUG_MODE -g


LD       = gfortran
#LD       = g95
LDFLAGS  = -L$(LIBMBOARD_LIB)
LDFLAGS += -L$(PGPLOT_DIR)
LDFLAGS += -L$(X11_DIR)
LIBS	 = -lcpgplot -lpgplot -lpng

LIBS    += -lmboard_sd  -lm

#FLAME source files
FLAME   = main.c memory.c xml.c messageboards.c partitioning.c rules.c timing.c

#FLAME auxilary files
AUX 	= stategraph.dot stategraph_colour.dot process_order_graph.dot Doxyfile latex.tex

# FLAME generated model files
SOURCES =  agent_a_functions.c  agent_b_functions.c 
HEADERS = header.h low_primes.h mboard.h  agent_a_agent_header.h  agent_b_agent_header.h 

DEPS    = Makefile header.h low_primes.h

OBJECTS = $(SOURCES:.c=.o) $(FLAME:.c=.o)
EXECUTABLE = main
RM = rm -f

all: $(SOURCES) $(FLAME) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o $@ $(LIBS)

$(OBJECTS): $(DEPS)

.c.o:
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJECTS) $(EXECUTABLE) $(EXECUTABLE).exe 
vclean:
	$(RM) main $(EXECUTABLE) $(EXECUTABLE).exe $(OBJECTS)  $(FLAME) $(HEADERS)  $(AUX) Makefile
format:
	astyle -A3 $(SOURCES)
	for file in $(patsubst %.c,%.h, $(SOURCES)) ; do \
	echo $$file ; \
	astyle -A3 $$file ; \
	done 
print:
	a2ps -R -f10 --column=1 $(SOURCES)
