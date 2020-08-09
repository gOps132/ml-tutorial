cmake_minimum_required(VERSION 3.14)
project(knn
    VERSION 1.0.0
    DESCRIPTION "implementation of the knn (k nearest neighbors) algorithm"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)

set(KNN_SOURCES
    src/knn.cpp
)

option(KNN_BUILD_EXAMPLE OFF)

if(KNN_BUILD_EXAMPLE)
    add_executable(${PROJECT_NAME} ${KNN_SOURCES})
else()
    # visibility options here
    add_library(${PROJECT_NAME} SHARED ${KNN_SOURCES})
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE mnist_ml
)