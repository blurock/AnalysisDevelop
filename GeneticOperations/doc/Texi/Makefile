# FILE     Makefile
# PACKAGE  GeneticOperations 
# AUTHOR   Edward S. Blurock
#
# CONTENT
#   GNU Makefile for the STURM documentation.
#
# COPYRIGHT (C) 1997 CoreObjects Library

include ../../etc/CoreObjects/MakeDef

#V Variable definitions.
PackageRoot:=$(shell cd ..; pwd)
export PackageRoot
texidirs:=$(filter-out %/Config,$(shell cd ../../src; find * -type d -print ))


#F Targets.

all: dvi info texi html

dvi: texi
	@echo Building "doc/GeneticOperations.dvi" ...
	-@texi2dvi GeneticOperations.texi
	@mv GeneticOperations.dvi ..
	@echo Building "doc/GeneticOperations.dvi" finished.

info: texi
	@echo Building "info/GeneticOperations.info*" ...
	-@makeinfo --no-validate --error-limit 10 GeneticOperations.texi
	@$(RM) -f ../../info/*.info*
	@mv *.info* ../../info
	@echo Building "info/GeneticOperations.info*" finished.

html: texi
	@echo Building "doc/*.html" ...
	@$(RM) -f ../*.html
	-@cd ..; texi2html -expandinfo -split_node -verbose -menu Texi/GeneticOperations.texi
	@echo Building "doc/*.html" finished.

texi:
	@echo Creating directories ...
	@-umask 000; mkdir Functions 2>/dev/null
	@-umask 000; cd Functions; mkdir $(texidirs) 2>/dev/null
	@echo Building .texi files in \"Functions/*\" ...
	@find Functions/* -type d -exec \
	  $(MAKE) --no-print-directory -f $(CodeBaseRoot)/etc/CoreObjects/Makefile.doc -C {} all \;
	@echo Building function specifications \"Functions.texi\" ...
	@$(RM) Functions.texi
	@makesturmappendix Functions >Functions.texi
	@echo Building "Packages.texi" ...
	@$(RM) Packages.texi
	@cp Packages.head Packages.texi
	@echo >>Packages.texi @menu
	@find >>Packages.texi \
	  * -type d ! -name Functions \
	  -exec echo '*' {} Package:: \; -o '(' -name Functions -prune ')'
	@echo >>Packages.texi @end menu
	@find >>Packages.texi * -name Main.texi -exec echo @include {} \;
	@echo Building package description in \"GeneticOperations/\" ...
	@cd GeneticOperations; rm -f Classes.texi Overview.texi;\
	 touch Classes.texi Overview.texi;\
	 package2texi <../../../include/CoreObjects/GeneticOperationsType.hh
	@echo Building .texi files finished.


clean::
	$(RM) -f *.aux *.log *.cp *.fn *.ky *.tp *.toc *.vr *.pg *.fns *.cps

cleaner::
	find Functions -type d -exec \
	  $(MAKE) -s -f $(CodeBaseRoot)/etc/CoreObjects/Makefile.doc CLEAN=1 -C {} cleaner \;
	$(RM) Functions.texi Packages.texi *.dvi *.info*
	$(RM) GeneticOperations/Classes.texi GeneticOperations/Overview.texi
	$(RM) ../*.html ../*.dvi ../../info/*.info*

#f Special targets.

.PHONY:	dvi info texi
