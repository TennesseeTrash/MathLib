Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.1
)

FetchContent_MakeAvailable(Catch2)

add_executable(Tests)

target_link_libraries(Tests PRIVATE
    ccMath
    Catch2::Catch2WithMain
)

target_sources(Tests PRIVATE
    "TestVectors.cpp"
)

set_property(TARGET Tests PROPERTY CXX_STANDARD 20)

if(MSVC)
    target_compile_options(Tests PRIVATE /W4)
else()
    target_compile_options(Tests PRIVATE -Weverything -Wpedantic -Wno-c++98-compat -Wno-c++98-compat-pedantic)
endif()
