@rem !/bin/msdos
@
@echo %cd%
@
@cl /EHsc  -I../../../src coord.cpp
@
@cd circle
@call make.bat
@cd ..
@
@cd direction
@call make.bat
@cd ..
@
@cd ellipse
@call make.bat
@cd ..
@
@cd interval
@call make.bat
@cd ..
@
@cd plane
@call make.bat
@cd ..
@
@cd projective
@call make.bat
@cd ..
@
@cd quadric
@call make.bat
@cd ..
@
@cd triangle
@call make.bat
@cd ..
@
@cd tetrahedron
@call make.bat
@cd ..
@
@cd triangle
@call make.bat
@cd ..
@