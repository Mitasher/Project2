#pragma once
#include "vector.h"
class matrica {
private:
    Nas** mat;
    int rows;
    int cols;

public:
    matrica(int rows, int cols);
    matrica(std::vector<std::vector<float>> data);
    matrica( const matrica& other);
    matrica(matrica&& other);
    ~matrica();
    matrica() : mat(nullptr), rows(1),cols(1) {};
    void print();
    matrica& operator = (const matrica&);
    matrica operator + (matrica&);
    bool operator == (matrica&);
};

