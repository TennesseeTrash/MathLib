
add_library(MathLib INTERFACE)

target_include_directories(MathLib
    INTERFACE
    "Include"
)

target_compile_features(MathLib
    INTERFACE
    cxx_std_20
)
