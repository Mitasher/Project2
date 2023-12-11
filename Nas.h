#pragma once
#include "Des.h"
class Nas : public Des
{
	private:
		char flag=' ';

	public:
		Nas(double value) : Des(value) {
			if (abs(cel) > 1000) {
				flag = '*';
				if (cel > 0) {
					cel = 1000;
				}
				else { cel = -1000; }
			}
			}

		Nas() : Des(0.0), flag(' ') {
		}

		Nas(int a1, int a2) : Des(a1, a2) {
			
		}
		Nas(const Des& desResult,char flag) : Des(desResult) {
			if (flag == '*') {
			flag = '*';
			}
			if (abs(cel) > 1000) {
				flag = '*';
				if (cel > 0) {
					cel = 1000;
				}
				else {
					cel = -1000;
				}
			}
			drob = drob * 1000;
		}		
		void print();	
		friend Nas operator+(Nas , Nas );
		friend Nas operator -(Nas a1, Nas a2 );
		friend  Nas operator *(Nas, Nas);
		friend Nas operator /(Nas, Nas);
};


