@rem !/bin/msdos
@
@echo %cd%
@
@cl /EHsc  -I../../../../src check.cpp
@cl /EHsc  -I../../../../src eigen_test.cpp
@cl /EHsc  -I../../../../src invert_test.cpp
@cl /EHsc  -I../../../../src test.cpp
@
