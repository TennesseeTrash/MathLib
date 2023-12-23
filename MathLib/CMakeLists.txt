
add_library(MathLib INTERFACE)

target_include_directories(MathLib
    INTERFACE
    "Include"
)

target_compile_features(MathLib
    INTERFACE
    cxx_std_20
)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    message(
        FATAL_ERROR
        "MathLib is currently not supported on MSVC."
    )
endif()
