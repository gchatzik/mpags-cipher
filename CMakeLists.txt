# - Main CMake buildscript for mpags-cipher
# Comments in a CMake Script are lines begining with a '#'

# - Set CMake requirements then declare project
cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When Makefiles are generated, output all command lines by default
#   Do this to begin with so it's easy to see what compiler command/flags
#   are used. This can also be done by removing the 'set' command and
#   running make as 'make VERBOSE=1'.
set(CMAKE_VERBOSE_MAKEFILE ON)


if(CMAKE_CXX_COMPILER_ID MATCHES "GNUIClang|AppleClang")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Werror -Wfatal-errors -Wshadow -pedantic")
  endif()

add_executable(mpags.cipher 
  mpags.cipher.cpp
  MPAGSCipher/transformChar.cpp
  MPAGSCipher/transformChar.hpp
  MPAGSCipher/processCommandLine.cpp
  MPAGSCipher/processCommandLine.hpp
  MPAGSCipher/CaesarCipher.cpp
  MPAGSCipher/CaesarCipher.hpp)


target_include_directories(mpags.cipher PRIVATE MPAGSCipher)


target_compile_features(mpags.cipher PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization)


# - Install mpags.cipher
include(GNUInstallDirs)
install(TARGETS mpags.cipher DESTINATION ${CMAKE_INSTALL_BINDIR})

set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})
include(CPack)
