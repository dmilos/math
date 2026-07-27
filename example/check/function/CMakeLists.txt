#cmake_minimum_required(VERSION 2.8)

add_executable(   Math_FunctionBais                 bais.cpp )
add_executable(   Math_FunctionClamper_Test         clamper_test.cpp )
add_executable(   Math_FunctionDistribution         distribution.cpp )
add_executable(   Math_FunctionFactorial            factorial.cpp )
add_executable(   Math_FunctionGabor                gabor.cpp )
add_executable(   Math_FunctionGain                 gain.cpp )

add_executable(   Math_FunctionHilbert_Test         hilbert_test.cpp )


add_executable(   Math_FunctionLebesgue_Test        lebesgue_test.cpp )
add_executable(   Math_FunctionPower                power.cpp )
add_executable(   Math_FunctionVal                  val.cpp )
add_executable(   Math_FunctionVap                  vap.cpp )
add_executable(   Math_FunctionGcd                  gcd.cpp )

 
if(DEFINED ENV{OPENCV__msvc__INCLUDE_x} )
    add_executable(   Math_FunctionHilbertOCV_Test      hilbertOCV_test.cpp lebesgue_ocv.cpp )

        target_include_directories( Math_FunctionHilbertOCV_Test  PUBLIC  $ENV{OPENCV__msvc__INCLUDE} )
        target_include_directories( Math_FunctionHilbertOCV_Test  PUBLIC  $ENV{MATH_ROOT} )
        target_link_libraries ( Math_FunctionHilbertOCV_Test
            debug     $ENV{OPENCV__msvc_64_LIBFILE_DEBUG}
            optimized $ENV{OPENCV__msvc_64_LIBFILE_RELEASE}
        )

        target_link_directories( Math_FunctionHilbertOCV_Test
            PUBLIC $<$<CONFIG:DEBUG>:$ENV{OPENCV__msvc_64_LIBDIR_DEBUG}>
            PUBLIC $<$<CONFIG:RELEASE>:$ENV{OPENCV__msvc_64_LIBDIR_RELEASE}>
        )

        set( OPENCV_BIN_DEBUG   $ENV{OPENCV__msvc_64_DLLDIR_DEBUG}   )
        set( OPENCV_BIN_RELEASE $ENV{OPENCV__msvc_64_DLLDIR_RELEASE} )

        if( MSVC ) 
            configure_file( templatevcxproj.user.in Math_FunctionHilbertOCV_Test.vcxproj.user   )
        endif()

endif()


 



 