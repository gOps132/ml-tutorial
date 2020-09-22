#include "knn.hpp"

#include <cmath>
#include <limits>
#include <map>
#include <stdint.h>

#include "data_handler.hpp"

knn::knn(int val)
    : m_k(val)
{
}

// 0(N)^2 if K ~ N
// if K = 2 then 0(~N )

void knn::find_knearest(data *query_point)
{
    m_neighbors = new std::vector<data *>;
    double min = std::numeric_limits<double>::max();
    double previous_min = min;
    int index = 0;
    for (int i = 0; i < m_k; i++)
    {
        if (i)
        {
            for (int j = 0; j < m_training_data->size(); j++)
            {
                double distance = calculate_distance(query_point, m_training_data->at(j));
                m_training_data->at(j)->set_distance(distance);
                if (distance < min)
                {
                    min = distance;
                    index = j;
                }
            }
            m_neighbors->push_back(m_training_data->at(index));
            previous_min = min;
            min = std::numeric_limits<double>::max();
        }
        else
        {
            for (int j = 0; j < m_training_data->size(); j++)
            {
                double distance = calculate_distance(query_point, m_training_data->at(j));
                if(distance < previous_min && distance < min)
                {
                    min = distance;
                    index = j;
                }
            }
            m_neighbors->push_back(m_training_data->at(index));
            previous_min = min;
            min = std::numeric_limits<double>::max();
        }
    }
}

void knn::set_training_data(std::vector<data *> *vect)
{
    m_training_data = vect;
}

void knn::set_test_data(std::vector<data *> *vect)
{
    m_test_data = vect;
}

void knn::set_validation_data(std::vector<data *> *vect)
{
    m_validation_data = vect;
}

void knn::set_k(int val)
{
    m_k = val;
}

int knn::predict()
{
    std::map<uint8_t, int> class_freq;
    for(int i = 0; i < m_neighbors->size(); i++)
    {
        if(class_freq.find(m_neighbors->at(i)->get_label()) == class_freq.end())
        {
            class_freq[neighbors];
        }
    }
}

double knn::calculate_distance(data *query_point, data *input)
{
    double distance = 0.0;
    if (query_point->get_feature_vector_size() != input->get_feature_vector_size())
    {
        printf("Error Vector Size Mismatched");
        exit(1);
    }
#ifdef EUCLID
    for (unsigned i = 0; i < query_point->get_feature_vector_size(); i++)
    {
        // square root of the sum of the differences^^2 of dot products between each feature vector
        distance = pow(query_point->get_feature_vector()->at(i) - input->get_feature_vector()->at(i), 2);
    }
    distance = sqrt(distance);
#elif defined MANHATTAN
    // put manhattan impl here
#endif
    return distance;
}

double knn::validate_performance()
{
}

double knn::test_performance()
{
}
