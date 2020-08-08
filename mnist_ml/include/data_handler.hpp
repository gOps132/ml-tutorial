#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
#include "stdint.h"
#include "data.hpp"

class data_handler
{
private:
    /* All of the data presplit */
    std::vector<data*> *data_array;
    std::vector<data*> *training_data;
    std::vector<data*> *test_data;
    std::vector<data*> *validation_data;

    /* count the number of classess that we have */
    int num_classes;
    int feature_veactor_size;
    /* each*/
    std::map<uint8_t, int> class_map;
    
    const double TRAIN_SET_PERCENT = 0.75;
    const double TEST_SET_PERCENT = 0.20;
    const double VALIDATION_PERCENT = 0.05;
public:
    data_handler();
    ~data_handler();

/* Data file and label files of the mnist dataset are separeted */

    void read_feature_vector(std::string path);
    void read_feature_labels(std::string path);
    /* Take the full data array and divide into training, test, and validation data */  
    void split_data();
    void count_classes();

    uint32_t convert_little_endian(const unsigned char* bytes);

    std::vector<data*> *get_training_data();
    std::vector<data*> *get_test_data();
    std::vector<data*> *get_validation_data();
};