#pragma once
#include <math.h>
class Des
{
protected:
	int cel, drob;
public:
	Des (double value) {
		int exp=1000;
		cel = int(value);
		drob= int((value-cel)*1000);
		
	}

	Des(int a1, int a2){
		cel = a1;
		if (a2 <= 999) {
			drob = a2;
		}
		else {
			drob = a2 / 1000;
		}

		} 
	void print();
	friend Des operator +(Des a1, Des a2);
	friend Des operator -(Des a1, Des a2);
	friend Des operator *(Des, Des);
	friend Des operator /(Des, Des);
	bool operator == (Des);
	bool operator != (Des);
};
