.DEFAULT_GOAL := doc
SHELL := /bin/bash

ECHO ?= echo -e

.PHONY: doc
doc:
	@cd doc; make html

.PHONY: cleandoc
cleandoc:
	-rm -r doc/_build
	-rm -r doc/_doxygen
