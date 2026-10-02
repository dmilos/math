

rem mkdir _build-msvc
rem cd _build-msvc
rem %prg_cmake% ..
rem %prg_cmake% --build .
rem cd ..

rem pause
rem exit
rem 
rem mkdir _build-msvc_11
rem cd _build-msvc_11
rem %prg_cmake% ..   -DCMAKE_CXX_STANDARD=11 -DCMAKE_CXX_STANDARD_REQUIRED=ON
rem %prg_cmake% --build .
rem cd ..
rem 
rem mkdir _build-msvc_14
rem cd _build-msvc_14
rem %prg_cmake% ..   -DCMAKE_CXX_STANDARD=14 -DCMAKE_CXX_STANDARD_REQUIRED=ON
rem %prg_cmake% --build ..
rem cd ..
rem 
rem mkdir _build-msvc_17
rem cd _build-msvc_17
rem %prg_cmake% ..   -DCMAKE_CXX_STANDARD=17 -DCMAKE_CXX_STANDARD_REQUIRED=ON
rem %prg_cmake% --build .
rem cd ..
rem 
rem mkdir _build-msvc_20
rem cd _build-msvc_20
rem %prg_cmake% ..   -DCMAKE_CXX_STANDARD=20 -DCMAKE_CXX_STANDARD_REQUIRED=ON
rem %prg_cmake% --build .
rem cd ..


mkdir _build-msvc_Clang_11
cd _build-msvc_Clang_11
%prg_cmake% ..   -DCMAKE_CXX_STANDARD=11 -DCMAKE_CXX_STANDARD_REQUIRED=ON -T ClangCL
%prg_cmake% --build .
cd ..

rem mkdir _build-msvc_Clang_14
rem cd _build-msvc_Clang_14
rem %prg_cmake% ..   -DCMAKE_CXX_STANDARD=14 -DCMAKE_CXX_STANDARD_REQUIRED=ON -T ClangCL
rem %prg_cmake% --build .
rem cd ..
rem 
rem mkdir _build-msvc_Clang_17
rem cd _build-msvc_Clang_17
rem %prg_cmake% ..   -DCMAKE_CXX_STANDARD=17 -DCMAKE_CXX_STANDARD_REQUIRED=ON -T ClangCL
rem %prg_cmake% --build .
rem cd ..
rem 
rem mkdir _build-msvc_Clang_20
rem cd _build-msvc_Clang_20
rem %prg_cmake% ..   -DCMAKE_CXX_STANDARD=20 -DCMAKE_CXX_STANDARD_REQUIRED=ON -T ClangCL
rem %prg_cmake% --build .
rem cd ..


rem TODO   -T v141,v142,v143

pause
