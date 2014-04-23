# FILE     Makefile
# PACKAGE  MixedClasses
# AUTHOR   Edward S. Blurock
#
# CONTENT
#   GNU Makefile for the package library "libMixedClasses.a
#
# COPYRIGHT (C)  1997 Basis Library

#V PackageRoot . . . . . . . . . . . . . . The root directory of this package.
PackageRoot:=$(shell cd ..; pwd)
export PackageRoot


#I
include ../etc/Basis/MakeDef


#V Variable definitions.

objdirs:=$(filter-out %/Config,$(shell cd ../src; find * -type d ! -name seq ! -name par ! -name CVS -print))


#F Targets.

all: libMixedClasses.a

libMixedClasses.a:
	@echo Building sources ...
	for i in `find ../src/* -name Makefile -print`; do\
	  $(MAKE) -C `dirname $$i` all ;\
	done
	@echo Building objects ...
	@-mkdir ../obj; cd ../obj; mkdir $(objdirs) 2>/dev/null
	find ../obj/* -type d ! -name CVS -exec \
	  $(MAKE) -f $(PackageRoot)/etc/Basis/Makefile.obj -C {} all \;
	@echo Building library ...
	$(RM) libMixedClasses.a
	ar -vq libMixedClasses.a `find ../obj -name '*.o' -print` 
	$(RANLIB) libMixedClasses.a

clean::
	find ../obj/* -type d ! -name CVS -exec \
	  $(MAKE) -f $(PackageRoot)/etc/Basis/Makefile.obj CLEAN=1 -C {} clean \;

cleaner::
	$(RM) lib*.a

#f Special targets.

.PHONY:	libMixedClasses.a
