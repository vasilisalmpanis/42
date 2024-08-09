cmake_minimum_required(VERSION 3.10)

project(CGPACalculator VERSION 1.0)

set(SOURCES
    src/main.cpp
    src/cgpacalculator.cpp
)
add_executable(CGPACalculator ${SOURCES})
target_include_directories(CGPACalculator PUBLIC 
				"${CMAKE_CURRENT_SOURCE_DIR}/include")

target_compile_features(CGPACalculator PRIVATE cxx_std_11)
