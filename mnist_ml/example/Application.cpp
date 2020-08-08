#include "data.hpp"
#include "data_handler.hpp"

int main()
{
    data_handler *dh = new data_handler();
    dh->read_feature_vector("/home/gian/dev/ml/ml-tutorial/assets/train-images-idx3-ubyte");
    dh->read_feature_labels("/home/gian/dev/ml/ml-tutorial/assets/train-labels-idx1-ubyte");
    dh->split_data();
    dh->count_classes();
}