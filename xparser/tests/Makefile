# Makefile for run test xparser

CC         = gcc
CFLAGS     = -c -g -std=c99 -Wall -pedantic -posix
LDFLAGS    = -lcunit
SOURCES    = run_test.c
OBJECTS    = $(SOURCES:.c=.o)
EXECUTABLE = run_test
DEPS       = Makefile
RM         = rm -f

#==============================================================
#
# Set these variables
LIBMBOARD  = LIBMBOARD_DIR=/home/cg/SANDBOX/xagents/libmboard
FLAME_XPARSER_DIR = FLAME_XPARSER_DIR=/home/cg/SANDBOX/xagents/xparser

all: build run

#run: test1/libmboard build
run: build
	./run_test $(LIBMBOARD) $(FLAME_XPARSER_DIR)

test1/libmboard:
	cd $(LIBMBOARD); ./autogen.sh; ./configure --prefix=`pwd`/../../../trunk/xparser/tests/test1/libmboard; make; make install; cd ../../../trunk/xparser/tests

build: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

$(OBJECTS): $(DEPS)

.c.o:
	$(CC) $(CFLAGS) $< -o $@

vclean:
	$(RM) *.o run_test.exe run_test

