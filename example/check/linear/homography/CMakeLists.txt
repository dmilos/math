#cmake_minimum_required(VERSION 2.8)
if( NOT DEFINED CMAKE_PROJECT_NAME OR CMAKE_PROJECT_NAME STREQUAL "" )
  project( MathExampleLinearHomographyOCV )
endif()

add_executable(   Math_Linear_Homography__check             check.cpp )
#add_executable(   Math_Linear_Homography__check2             check2.cpp )
add_executable(   Math_Linear_Homography__test             test.cpp )

add_subdirectory(   ocv )