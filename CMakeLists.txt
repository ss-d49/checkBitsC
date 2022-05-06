cmake_minimum_required (VERSION 3.1.0 FATAL_ERROR)
project(study C)

file( GLOB SOURCES src/*.c )

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c2x -Os -O3 -s -static -static-libgcc")

option(BUILD_32BIT "Build 32-bit binaries." OFF)

if(BUILD_32BIT)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -march=i386")
endif(BUILD_32BIT)

add_executable(${PROJECT_NAME}
	${SOURCES}
)

install(TARGETS ${PROJECT_NAME} DESTINATION .)
