#cmake_minimum_required(VERSION 2.8)


set( DIECTION_OPENCV_PRJ Math_Geometry_Direction_OCV )
add_executable(   ${DIECTION_OPENCV_PRJ}             testOCV.cpp )

if( MSVC )
    target_include_directories( ${DIECTION_OPENCV_PRJ}  PUBLIC  $ENV{OPENCV__msvc__INCLUDE} )
    target_link_libraries ( ${DIECTION_OPENCV_PRJ}
        debug     $ENV{OPENCV__msvc_64_LIBFILE_DEBUG}
        optimized $ENV{OPENCV__msvc_64_LIBFILE_RELEASE}
     )

    target_link_directories( ${DIECTION_OPENCV_PRJ}
        PUBLIC $<$<CONFIG:DEBUG>:$ENV{OPENCV__msvc_64_LIBDIR_DEBUG}>
        PUBLIC $<$<CONFIG:RELEASE>:$ENV{OPENCV__msvc_64_LIBDIR_RELEASE}>
     )

    set( OPENCV_BIN_DEBUG   $ENV{OPENCV__msvc_64_DLLDIR_DEBUG}   )
    set( OPENCV_BIN_RELEASE $ENV{OPENCV__msvc_64_DLLDIR_RELEASE} )
    configure_file( templatevcxproj.user.in ${DIECTION_OPENCV_PRJ}.vcxproj.user   )

endif()

