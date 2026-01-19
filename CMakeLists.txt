cmake_minimum_required(VERSION 3.14)
project(CODEWARS)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


add_executable(run_tests googleTest.cpp) 

target_link_libraries(run_tests gtest_main)

include(GoogleTest)
#enable_testing()

#gtest_discover_tests(run_tests)