# FILE     Makefile
# PACKAGE  FunctionReal1DObjects
# AUTHOR   Edward S. Blurock
#
# CONTENT
#   GNU Makefile for the package library "libFunctionReal1DObjects.a
#
# COPYRIGHT (C)  1997 CoreObjects Library

#V PackageRoot . . . . . . . . . . . . . . The root directory of this package.
PackageRoot:=$(shell cd ..; pwd)
export PackageRoot


#I
include ../etc/CoreObjects/MakeDef


#V Variable definitions.

objdirs:=$(filter-out %/Config,$(shell cd ../src; find * -type d ! -name seq ! -name par ! -name CVS -print))


#F Targets.

all: libFunctionReal1DObjects.a

libFunctionReal1DObjects.a:
	@echo Building sources ...
	for i in `find ../src/* -name Makefile -print`; do\
	  $(MAKE) -C `dirname $$i` all ;\
	done
	@echo Building objects ...
	@-mkdir ../obj; cd ../obj; mkdir $(objdirs) 2>/dev/null
	find ../obj/* -type d ! -name CVS -exec \
	  $(MAKE) -f $(PackageRoot)/etc/CoreObjects/Makefile.obj -C {} all \;
	@echo Building library ...
	$(RM) libFunctionReal1DObjects.a
	ar -vq libFunctionReal1DObjects.a `find ../obj -name '*.o' -print` 
	$(RANLIB) libFunctionReal1DObjects.a

clean::
	find ../obj/* -type d ! -name CVS -exec \
	  $(MAKE) -f $(PackageRoot)/etc/CoreObjects/Makefile.obj CLEAN=1 -C {} clean \;

cleaner::
	$(RM) lib*.a

#f Special targets.

.PHONY:	libFunctionReal1DObjects.a
