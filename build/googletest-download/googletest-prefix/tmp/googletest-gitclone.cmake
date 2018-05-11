if("master" STREQUAL "")
  message(FATAL_ERROR "Tag for git checkout should not be empty.")
endif()

set(run 0)

if("/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitinfo.txt" IS_NEWER_THAN "/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt")
  set(run 1)
endif()

if(NOT run)
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E remove_directory "/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-src'")
endif()

# try the clone 3 times incase there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git" clone "https://github.com/google/googletest.git" "googletest-src"
    WORKING_DIRECTORY "/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/google/googletest.git'")
endif()

execute_process(
  COMMAND "/usr/bin/git" checkout master
  WORKING_DIRECTORY "/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: 'master'")
endif()

execute_process(
  COMMAND "/usr/bin/git" submodule init
  WORKING_DIRECTORY "/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to init submodules in: '/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-src'")
endif()

execute_process(
  COMMAND "/usr/bin/git" submodule update --recursive
  WORKING_DIRECTORY "/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitinfo.txt"
    "/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt"
  WORKING_DIRECTORY "/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/mnt/c/Users/Thomas/Documents/Modelisation/cpp/tp1_lelettyt_gardelcl/build/googletest-download/googletest-prefix/src/googletest-stamp/googletest-gitclone-lastrun.txt'")
endif()

