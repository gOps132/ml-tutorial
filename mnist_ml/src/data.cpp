#include "data.hpp"

/*
    No class at end 
    std::vector<uint8_t>* feature_vector;
    uint8_t label;
    int enum_label;
*/

data::data(std::vector<uint8_t> *fv)
    : feature_vector(fv)
{
}

data::~data()
{
    delete feature_vector;
}

void data::set_feature_vector(std::vector<uint8_t> *vect)
{
    feature_vector = vect;
}

void data::append_to_feature(uint8_t val)
{
    feature_vector->push_back(val);
}

void data::set_label(uint8_t val)
{
    label = val;
}

void data::set_enumerated_label(int val)
{
    enum_label = val;
}

int data::get_feature_vector_size()
{
    return feature_vector->size();
}

uint8_t data::get_label()
{
    return label;
}

uint8_t data::get_enumerated_label()
{
    return enum_label;
}

std::vector<uint8_t> *data::get_feature_vector()
{
    return feature_vector;
}
