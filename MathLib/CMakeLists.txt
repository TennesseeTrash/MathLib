add_library(MathLib INTERFACE)
target_include_directories(MathLib INTERFACE "Include")
set_property(TARGET MathLib PROPERTY CXX_STANDARD 20)
