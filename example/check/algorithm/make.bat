@rem !/bin/msdos
@
@echo %cd%
@
@cl /EHsc  -I../../../src combination_test.cpp
@cl /EHsc  -I../../../src variation_test.cpp
@