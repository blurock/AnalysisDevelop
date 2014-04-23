# FILE     Makefile
# PACKAGE  PopulationBasedOptimization
# AUTHOR   Edward S. Blurock
#
# CONTENT
#   GNU Makefile for the package library "libPopulationBasedOptimization.a
#
# COPYRIGHT (C)  1997 CoreObjects Library PackageRoot . . . . . . . . . . . . . . The root directory of this package.
PackageRoot:=$(shell cd ..; pwd)
export PackageRoot



#I ../etc/CoreObjects/MakeDef


#V Variable definitions.

objdirs:=$(filter-out %/Config,$(shell cd ../src; find * -type d ! -name seq ! -name par ! -name CVS -print))


#F Targets.

all: libPopulationBasedOptimization.a

libPopulationBasedOptimization.a:
	@echo Building sources ...
	for i in `find ../src/* -name Makefile -print`; do\
	  $(MAKE) -C `dirname $$i` all ;\
	done
	@echo Building objects ...
	@-mkdir ../obj; cd ../obj; mkdir $(objdirs) 2>/dev/null
	find ../obj/* -type d ! -name CVS -exec \
	  $(MAKE) -f $(PackageRoot)/etc/CoreObjects/Makefile.obj -C {} all \;
	@echo Building library ...
	$(RM) libPopulationBasedOptimization.a
	ar -vq libPopulationBasedOptimization.a `find ../obj -name '*.o' -print` 

clean::
	find ../obj/* -type d ! -name CVS -exec \
	  $(MAKE) -f $(PackageRoot)/etc/CoreObjects/Makefile.obj CLEAN=1 -C {} clean \;

cleaner::
	$(RM) lib*.a

#f Special targets.

.PHONY:	libPopulationBasedOptimization.a
