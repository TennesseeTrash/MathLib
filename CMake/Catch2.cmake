if(NOT TARGET Catch2::Catch2WithMain)
    include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG        v3.5.0
    )

    FetchContent_MakeAvailable(Catch2)
endif()
