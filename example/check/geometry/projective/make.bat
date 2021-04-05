@rem !/bin/msdos
@
@echo %cd%

@cd camera
@call ./make.bat
@cd ..
@
@cl /EHsc  -I../../../../src check.cpp
@
