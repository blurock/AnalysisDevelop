# FILE     Makefile
# PACKAGE  BasicIO
# AUTHOR   Mario Drobics
#
# CONTENT
#   Makefile for example programs of the "BasicIO" package.
#
# COPYRIGHT (C)  1997 Basis Library

#V PackageRoot . . . . . . . . . . . . . . The root directory of this package.
PackageRoot:=$(shell cd ../..; pwd)


#I
include ../../etc/Basis/MakeDef
OBJECTS=main.o
LDLIBS+=\
	-L$(PackageRoot)/lib\
	-L$(CodeBaseRoot)/lib\
        -lBasicIO


#V
ALL=otest


#F Targets.

all: $(ALL)

otest: $(OBJECTS)
	$(CC) -o otest $(OBJECTS) $(LDLIBS)

cleaner::
	$(RM) $(ALL)
