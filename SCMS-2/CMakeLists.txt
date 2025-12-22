cmake_minimum_required(VERSION 3.10)

project(SCMS LANGUAGES CXX)

# ===============================
# C++ Standard
# ===============================
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ===============================
# Include directory
# ===============================
include_directories(${PROJECT_SOURCE_DIR}/include)

# ===============================
# Source files (ATTENDENCE spelling)
# ===============================
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
    src/attendence.cpp
    src/attendenceManager.cpp
    src/exam.cpp
    src/marks.cpp
    src/examManager.cpp
    src/book.cpp
    src/libraryManager.cpp
)

# ===============================
# Executable
# ===============================
add_executable(scms ${SOURCES})

# ===============================
# Data & Logs setup
# ===============================
add_custom_target(create_dirs ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/data
    COMMAND ${CMAKE_COMMAND} -E make_directory ${PROJECT_SOURCE_DIR}/logs

    COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_SOURCE_DIR}/data/users.txt
    COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_SOURCE_DIR}/data/courses.txt
    COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_SOURCE_DIR}/data/attendence.txt
    COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_SOURCE_DIR}/data/exams.txt
    COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_SOURCE_DIR}/data/marks.txt
    COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_SOURCE_DIR}/data/books.txt
    COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_SOURCE_DIR}/data/transactions.log
    COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_SOURCE_DIR}/logs/scms.log
)

add_dependencies(scms create_dirs)
