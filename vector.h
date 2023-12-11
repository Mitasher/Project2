#pragma once
#include "Nas.h"
#include <vector>
class vector {
protected:
	Nas* vec;
	int len;
public:
	vector(int);
	vector(std::vector<float>);
	vector(vector&);
	vector(vector&&);
	~vector();
	vector() : vec(nullptr), len(1) {};
	inline int size() { return len; }
	inline Nas& el(int i) { return vec[i]; }
	Nas& operator [] (int);
	void operator = (vector&);
	bool operator == (vector&);
	vector operator + (vector&);
	vector operator /= (vector&);
	vector& operator += (vector&);
	vector operator - (vector&);
	void print();
};