add_executable(PathTracer)

target_compile_features(PathTracer
    PRIVATE
    cxx_std_20
)

target_include_directories(PathTracer
    PRIVATE
    "Include"
)

target_link_libraries(PathTracer
    PRIVATE
    MathLib
)

target_sources(PathTracer
    PRIVATE
    "Main.cpp"
    "Source/Camera.cpp"
    "Source/Framebuffer.cpp"
    "Source/Light.cpp"
    "Source/Material.cpp"
    "Source/Scene.cpp"
)
