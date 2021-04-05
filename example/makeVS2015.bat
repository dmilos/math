@rem !/bin/msdos
@
@rem  Make all examples.
@rem  No Scons, no CMake, no Make or any other make tool
@rem  One line one example
@rem  Designed for easy copy/paste
@
@rem  TODO MATH_USE_PP2FILE
@
@
@cls
@rem pushd .
@call "c:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\vcvars32.bat"
@rem popd
@
@echo %cd%
@
@cl /EHsc /I../src  readme.cpp
@
@cd ./check
@call ./make.bat
@cd ..
@

pause