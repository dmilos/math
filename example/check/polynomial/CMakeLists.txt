#cmake_minimum_required(VERSION 2.8)

add_subdirectory( interpolate )
add_subdirectory( solve )
add_subdirectory( linear )
add_subdirectory( quadric )

add_executable(  MathPlynomialEvaluate        evaluate.cpp )
add_executable(  MathPlynomialFit                  fit.cpp )
add_executable(  MathPlynomialNormalize      normalize.cpp )
add_executable(  MathPlynomialOptimize        optimize.cpp )

