cmake_minimum_required (VERSION 2.8.11)

project(TP1)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")

add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(test)
enable_testing ()
# Télécharge googletest au moment de la configureation
configure_file(cmake/CMakeLists.txt.in
               googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

# Ajout googletest directement au moment de la compilation
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src)

include_directories(${gtest_SOURCE_DIR}/test)

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND})

add_test (NAME test_Constructor COMMAND test_Constructor)
