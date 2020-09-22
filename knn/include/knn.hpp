#pragma once
 
#include <vector>
#include "data.hpp"

class knn 
{
private:
    int m_k;
    std::vector<data*> *m_neighbors;
    std::vector<data*> *m_training_data;
    std::vector<data*> *m_test_data;
    std::vector<data*> *m_validation_data;
public:
    knn(int val);

    void find_knearest(data *query_point);

    void set_training_data(std::vector<data *> *vect);

    void set_test_data(std::vector<data *> *vect);

    void set_validation_data(std::vector<data *> *vect);

    void set_k(int val);

    /* find most frequent class */  
    int predict();

    double calculate_distance(data* query_point, data* input);

    double validate_performance();

    double test_performance();
};