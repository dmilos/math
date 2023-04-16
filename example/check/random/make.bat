@rem !/bin/msdos
@
@echo %cd%
@
@cl /EHsc  -I../../../src sobol_test.cpp
@cl /EHsc  -I../../../src congruent_test.cpp
@
