#include "data_handler.hpp"

data_handler::data_handler()
{
    data_array = new std::vector<data*>;
    test_data = new std::vector<data*>;
    training_data = new std::vector<data*>;
    validation_data = new std::vector<data*>;
}

data_handler::~data_handler()
{
    delete data_array;
    delete test_data;
    delete training_data;
    delete validation_data;
}

void data_handler::read_feature_vector(std::string path)
{
    uint32_t header[4]; // [MAGIC_NUM|NUM_IMAGES|ROW_SIZE|COL_SIZE]
    unsigned char bytes[4]; //32 bits
    FILE *f = fopen(path.c_str(), "r");
    if(f)
    {
        for(int i = 0; i < 4; i++)
        {
            if(fread(bytes, sizeof(bytes), 1, f))
            {
                header[i] = convert_little_endian(bytes);
            }
        }
    }
    printf("done getting file header \n");
    int image_size = header[2]*header[3];
    for(int i = 0; i < header[1]; i++)
    {
        data *d = new data(new std::vector<uint8_t>);
    }
}

void data_handler::read_feature_labels(std::string path)
{

}

void data_handler::split_data()
{

}

void data_handler::count_classes()
{

}

uint32_t data_handler::convert_little_endian(const unsigned char *bytes)
{

}

std::vector<data *> data_handler::*get_training_data()
{

}

std::vector<data *> data_handler::*get_test_data()
{

}

std::vector<data *> data_handler::*get_validation_data()
{

}