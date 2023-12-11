#include "matrix.h"
#include <iostream>
void error1(const char* p) {
	printf("\nError code: %s", p);
	exit(EXIT_FAILURE);
}

matrix::matrix(int rows, int cols) : rows(rows), cols(cols) {
	if (rows <= 0 || cols <= 0)
		error1("Invalid matrix dimensions");

	mat = new vector[rows];
	vector p(cols);
	for (int i = 0; i < rows; ++i) {
		mat[i] = p;
	}
}

matrix::matrix(std::vector<std::vector<float>> data) {
	rows = data.size();
	if (rows <= 0)
		error1("Invalid matrix dimensions");

	cols = data[0].size();
	if (cols <= 0)
		error1("Invalid matrix dimensions");

	mat = new vector[rows];
	for (int i = 0; i < rows; ++i) {
		if (data[i].size() != cols)
			error1("Invalid matrix dimensions");
		vector temp(data[i]);
		mat[i] = temp;
	}
}

matrix::matrix(matrix& other) : rows(other.rows), cols(other.cols) {
	mat = new vector[rows];
	for (int i = 0; i < rows; ++i)
		mat[i] = other.mat[i];
}

matrix::matrix(matrix&& other) : mat(other.mat), rows(other.rows), cols(other.cols) {
	other.mat = nullptr;
	other.rows = 0;
	other.cols = 0;
}

matrix::~matrix() {
	delete[] mat;
}

// Ìועמהû
void matrix::print() {
	for (int i = 0; i < rows; ++i) {
		printf("[%d]\n", i);
		mat[i].print();
		printf("\n");
	}
}

matrix& matrix :: operator=(matrix& other) {
	if (this != &other) {
		delete[] mat;
		rows = other.rows;
		cols = other.cols;
		mat = new vector[rows];
		for (int i = 0; i < rows; ++i)
			mat[i] = other.mat[i];
	}
	return *this;
}

matrix matrix ::operator+(matrix& other) {
	if (rows != other.rows || cols != other.cols)
		error1("Matrix addition: different dimensions");

	matrix result(rows, cols);
	for (int i = 0; i < rows; ++i) {
		vector sum = mat[i] + other.mat[i];
		result.mat[i] = sum;
	}
	return result;
}

bool matrix ::operator == (matrix& x) {
	if (rows != x.rows || cols != x.cols) return false;
	for (int i = 0; i < rows; ++i) {
		if (mat[i] == x.mat[i]) {}
		else { return false; }
	}
	return true;
}


