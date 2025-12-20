cmake_minimum_required(VERSION 3.10)
project(SCMS)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(include)

# Source files
set(SOURCES
    src/main.cpp
    src/logger.cpp
    src/person.cpp
    src/student.cpp
    src/teacher.cpp
    src/admin.cpp
    src/authManager.cpp
    src/course.cpp
    src/courseManager.cpp
)

# Create executable
add_executable(scms ${SOURCES})

# Create data and logs directories
add_custom_target(create_dirs ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/data
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/logs
)