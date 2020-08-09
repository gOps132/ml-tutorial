cmake_minimum_required(VERSION 3.14)
project(mnist_ml
    VERSION 1.0.0
    DESCRIPTION "mnist-ml library"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

set(MNIST_ML_SOURCES
    src/data.cpp
    src/data_handler.cpp
)

# don't use build example when using as libs
option(MNIST_ML_BUILD_EXAMPLE OFF)

if(MNIST_ML_BUILD_EXAMPLE)
    set(MNIST_ML_SOURCES
        src/data.cpp
        src/data_handler.cpp
        example/Application.cpp
    )
    add_executable(${PROJECT_NAME} ${MNIST_ML_SOURCES})
else()
    add_library(${PROJECT_NAME} SHARED ${MNIST_ML_SOURCES})
endif()

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/bin/${PROJECT_NAME}"

    VERSION     ${PROJECT_VERSION}
    SONAME      ${PROJECT_VERSION_MAJOR}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)