@rem !/bin/msdos
@
@echo %cd%
@
@cl /EHsc  -I../../../../src conf.cpp
@cl /EHsc  -I../../../../src check.cpp
@cl /EHsc  -I../../../../src test.cpp
@cl /EHsc  -I../../../../src conf.cpp
@
