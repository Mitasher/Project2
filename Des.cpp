#include "Des.h"
#include "Nas.h"
#include <stdio.h>
void Des::print() {
	if (drob < 0) {
		drob = abs(drob);
		cel = abs(cel);
		printf("\n-");
		printf("%d.%.06d", cel, drob);
	}
	else {
		printf(" \n %d.%06d", cel, drob);
	}
}

Des operator+( Des a1, Des a2)  {
	int cel1, drob1, exp = 1000,sum, resultCel, resultDrob;
	cel1 = a1.cel * exp + a1.drob;
	drob1 = a2.cel * exp + a2.drob;
	sum = cel1 + drob1;
	resultCel = sum / exp;
	resultDrob = (sum % exp) * exp;
 	Des result(resultCel, resultDrob);
	return result;
}
Des operator -(Des a1, Des a2) {
	int cel1,  drob1, sum, exp = 1000, resultCel, resultDrob;
	cel1 = a1.cel*exp+a1.drob;
	drob1 = a2.cel * exp + a2.drob;
	sum = cel1 - drob1;
	resultCel = sum / exp;
	resultDrob = (sum % exp)*exp;
	Des result(resultCel, resultDrob);
	return result;
}
Des operator *(Des a1, Des a2) {
	long long a,cel1, drob1, exp=1000, resultCel, resultDrob;
	cel1 = a1.cel * exp + a1.drob;
	drob1 = a2.cel * exp + a2.drob;
	exp *= exp;
	a = cel1 * drob1;
	resultCel = a/exp;
	resultDrob = a%exp;
	Des result(resultCel, resultDrob);
	return result;
}
Des operator /(Des a1, Des a2) {
	int resultCel, resultDrob, cel1, drob1, exp = 1000;
	cel1 = a1.cel * exp + a1.drob;
	drob1 = a2.cel * exp + a2.drob;
	
		resultCel = cel1 / drob1;
		resultDrob = (((cel1-drob1* resultCel) * exp) / drob1)*1000;
		Des result(resultCel, resultDrob);
		return result;
}

bool Des::operator == (Des a) {
	return (cel == a.cel && drob == a.drob) ? true : false;
}
bool Des::operator != (Des a) {
	return (cel != a.cel || drob != a.drob) ? true : false;
}