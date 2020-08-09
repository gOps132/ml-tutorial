#pragma once

#include <vector>
#include "stdint.h"
#include "stdio.h"

/* The "container" of the handwritten mnist dataset */
class data
{
private:
    /* No class at end */
    std::vector<uint8_t>* feature_vector;
    uint8_t label;
    int enum_label;

    /* knn */
    double distance;
public:
    data();
    ~data();

    void set_feature_vector(std::vector<uint8_t>*);
    void append_to_feature_vector(uint8_t val);
    void set_label(uint8_t);
    void set_enumerated_label(int);

    int get_feature_vector_size();
    uint8_t get_label();
    uint8_t get_enumerated_label();
    
    std::vector<uint8_t> *get_feature_vector();

    /*knn*/
    void set_distance(double val);
};
