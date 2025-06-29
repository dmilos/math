#cmake_minimum_required(VERSION 3.28)

project( MathExampleReadMe )

include_directories( "../src" )

add_subdirectory( check )

add_executable(  MathExampleReadMe readme.cpp )

