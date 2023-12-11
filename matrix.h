#include "vector.h" 
#include <iostream>
class matrix {
private:
    vector* mat;
    int rows;
    int cols;

public:
    matrix(int rows, int cols);
    matrix(std::vector<std::vector<float>> data);
    matrix(matrix& other);
    matrix(matrix&& other);
    ~matrix();
    void print();
    matrix& operator = (matrix&);
    matrix operator + (matrix&);
    bool operator == (matrix&);
};
    



