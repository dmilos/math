#cmake_minimum_required(VERSION 2.8)

add_subdirectory( interpolate )
add_subdirectory( solve )
add_subdirectory( linear )
add_subdirectory( quadric )
add_subdirectory( cubic )
add_subdirectory( quartic )

add_executable(  Math_Plynomial_Evaluate        evaluate.cpp )
add_executable(  Math_Plynomial_Fit                  fit.cpp )
add_executable(  Math_Plynomial_Normalize      normalize.cpp )
add_executable(  Math_Plynomial_Optimize        optimize.cpp )

