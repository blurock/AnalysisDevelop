# FILE     Makefile
# PACKAGE  Statistics
# AUTHOR   Edward S. Blurock
#
# CONTENT
#   Makefile for example programs of the "Statistics" package.
#
# COPYRIGHT (C)  1997 Basis Library

#V PackageRoot . . . . . . . . . . . . . . The root directory of this package.
PackageRoot:=$(shell cd ../..; pwd)


#I
include ../../etc/Basis/MakeDef

LDLIBS+=\
  -lStatistics


#V
ALL= otest

OBJECTS = main.o

LIBS = 	\
	-L$(PackageRoot)/lib\
	-L$(CodeBaseRoot)/lib\
        -lStatistics\
        -lMatrix\
        -lMixedClasses\
        -lString\
        -lObjects\
        -lCommBuffer\
        -lSystem\
        -lMixedClasses\
        -lm



#F Targets.

all: $(ALL)

otest: $(OBJECTS)
	CompileC++ -o otest $(OBJECTS) $(LIBS)

cleaner::
	$(RM) $(ALL)
