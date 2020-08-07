cmake_minimum_required(VERSION 3.14)
project(mnist-ml
    VERSION 1.0.0
    DESCRIPTION "mnist-ml library"
    LANGUAGE CXX
)

set(MNIST_ML_SOURCES
    src/data.cpp
    src/data_handl.cpp
)

add_library(${PROJECT_NAME} ${MNIST_ML_SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}"

    VERSION     ${PROJECT_VERSION}
    SONAME      ${PROJECT_VERSION_MAJOR}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)