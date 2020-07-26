===================================================================

@@@@@@@ @          @    @     @ @@@@@@@
@       @         @ @   @@   @@ @
@       @        @   @  @ @ @ @ @
@@@@@   @       @     @ @  @  @ @@@@@
@       @       @@@@@@@ @     @ @
@       @       @     @ @     @ @
@       @@@@@@@ @     @ @     @ @@@@@@@

The Flexible Large-scale Agent Modelling Environment

xparser - FLAME program generator

(C) 2014 STFC Rutherford Appleton Laboratory/Sheffield University

===================================================================

FLAME is a generic agent-based modelling system which can be used 
to development applications in many areas. It generates a complete 
agent-based application which can be compiled and built on the 
majority of computing systems ranging from laptops to super-computers.

The FLAME web site www.flame.ac.uk contains details on FLAME and the
projects in which it has been used.

===================================================================

This directory contains all the files of the FLAME xparser

Files included
==============

xparser.c		- main program
dependencygraph.c	- dependency graph generator
memory.c		- memory generation and management
parsetemplate.c		- template parser and code generator
readmodel.c		- model reader

header.h		- xparser.c header file
Makefile		- make file

Template files
==============

These files are processed by the xparser to generate the application
code using the model (xml) and functions (c) files.

These file should not be changed in anyway:

main.tmpl
header.tmpl
low_primes.tmpl
memory.tmpl
messageboards.tmpl
partitioning.tmpl
rules.tmpl
timing.tmpl
xml.tmpl

Doxyfile.tmpl

It might be necessary to change this file to reflect your installation
of FLAME and the message board library files. DO SO WITH GREAT CARE.

Makefile.tmpl

Building the xparser
====================

Should be a simple 'make' command.

Running the xparser
===================

Given that the model developer will have written a model file(s) (.xml) and
set of transitions functions (.c file(s)) and referenced them with the
model file(s), running the xparser. Typing xparser will produce:

xparser (Version 0.17.1)
Usage: xparser [XMML file] [-s | -p] [-f]
        -s      Serial mode (default)
        -p      Parallel mode
        -f      Final production mode

The xparser requires the location on the template file. This can be provided
through the environment variable FLAME_XPARSER_DIR (recommended) or by making
links to or copies of the template files in the model directory (not a good idea).

If really necessary the template location can be explicitly compiled in to the xparser
by editing the FLAME_XPARSER_DIR macro in the xparser header file - header.h.

Using the GSL Library
=====================
Random numbers are very important to FLAME and the generators provided by the
native operating system may be consider inqdequate. FLAME provides a mechanism
for call the generators provided they have been installed on the target system.

By defining the <constant> GSL_RNG_SEED of type float in the <environment> section
of the model XML, the xparser will generator addition code to call GSL Random Number
Generators. In this version of FLAME this is only the mt19937 type of generator.

The seed of the generation sequence can be provide through the <GSL_RNG_SEED> tag
in the initial data. If the variable is not provided it is automatically set using
the current time.

The generator type and initial seed can be set using the system environment variable
GSL_RNG_TYPE and GSL_RNG_SEED. The seed provided in the initial data files will
override those given in system environment variables.


Chris Greenough - Feb 2014

