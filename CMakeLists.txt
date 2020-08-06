cmake_minimum_required(VERSION 3.14)
project(ml-tutorial
    DESCIRPTION "learning machine learning from scratch with c++ stl"
    LANGUAGES C CXX
)

set(SOURCES
    src/Application.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin"
)

target_link_libraries(${PROJECT_NAME}
    -lm
)