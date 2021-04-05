@rem !/bin/msdos
@
@rem  Make all examples.
@rem  No Scons, no CMake, no Make or any other make tool
@rem  One line one example
@rem  Designed for easy copy/paste
@
@rem  TODO COLOR_USE_PP2FILE
@
@
@rem  TODO g++ -fexceptions -std=c++11 -g -I../src akin.cpp
@
@cls
@rem call "c:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\vcvars32.bat"
@rem pushd .
@rem call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Professional\Common7\Tools\VsDevCmd.bat"
@rem popd
@call "c:\Program Files (x86)\Microsoft Visual Studio\2019\Enterprise\Common7\Tools\VsDevCmd.bat"
@
@echo %cd%
@
@cd ./check
@./make.bat
@cd ..
@
@cl /EHsc /I../src  readme.cpp

pause