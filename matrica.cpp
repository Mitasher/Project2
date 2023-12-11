#include "matrica.h"
void error(const char* p);

matrica :: matrica(int rows, int cols) : rows(rows), cols(cols) {
    if (rows <= 0 || cols <= 0) {
        error("Invalid matrix size.");
    }

    mat = new Nas * [rows];
    for (int i = 0; i < rows; ++i) {
        mat[i] = new Nas [cols];
    }
}

matrica::matrica (std::vector<std::vector<float>> data) : rows(data.size()), cols(data[0].size()) {
    mat = new Nas * [rows];
    for (int i = 0; i < rows; ++i) {
        mat[i] = new Nas [cols];
        for (int j = 0; j < cols; ++j) {
            mat[i][j] = data[i][j];
        }
    }
}

matrica::matrica(const matrica & other) : rows(other.rows), cols(other.cols) {
    mat = new Nas * [rows];
    for (int i = 0; i < rows; ++i) {
        mat[i] = new Nas [cols];
        for (int j = 0; j < cols; ++j) {
            mat[i][j] = other.mat[i][j];
        }
    }
}

matrica::matrica (matrica && other) : mat(other.mat), rows(other.rows), cols(other.cols) {
    other.mat = nullptr;
    other.rows = 0;
    other.cols = 0;
}

matrica::~ matrica () {
    for (int i = 0; i < rows; ++i) {
        delete[] mat[i];
    }
    delete[] mat;
}

void matrica::print() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            mat[i][j].print();
            printf("\t");
        }
        printf("\n");
    }
}
matrica& matrica :: operator=(const matrica& other) {
    if (this != &other) {
        delete[] mat;
        rows = other.rows;
        cols = other.cols;
        mat = new Nas * [rows];
        for (int i = 0; i < rows; ++i) {
            mat[i] = new Nas[cols];
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = other.mat[i][j];
            }
        }
    }
    return *this;
}

matrica matrica ::operator+(matrica & other) {
    if (rows != other.rows || cols != other.cols)
        error("Matrix addition: different dimensions");

    matrica result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            Nas sum = mat[i][j] + other.mat[i][j];
            result.mat[i][j] = sum;
        }
    }
    return result;
}

bool matrica ::operator == (matrica& x) {
    if (rows != x.rows || cols != x.cols) return false;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rows; ++j){
            if (mat[i][j] == x.mat[i][j]) {}
            else { return false; }
    }
}
    return true;
}