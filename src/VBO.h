#pragma once

//Vertex Buffer Object contains the data of a mesh attribute
class VBO
{
private:
    unsigned int vbo_id;
    unsigned int position;

public:
    VBO(unsigned int atribute_position, unsigned int atribute_size, float* data, unsigned int data_length);
    ~VBO();
};

