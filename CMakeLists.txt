# root cmakelists.txt file for mapping directories

cmake_minimum_required(VERSION 3.14)
project(ml_root)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/mnist_ml)

set(KNN_BUILD_EXAMPLE ON)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/knn)