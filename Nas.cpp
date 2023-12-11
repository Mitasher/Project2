#include "Nas.h"
#include "Des.h"
#include <stdio.h>
void Nas::print() {
       if (drob < 0) {
        drob = abs(drob);
        cel = abs(cel);
        printf("\n-");
        printf("%d.%.06d%c", cel, drob,flag);
    }
    else {
        printf("\n%d.%.06d%c", cel, drob, flag);
    }
}
Nas operator+( Nas a1,  Nas a2) {
    char flag;
    if ((a1.flag = '*') || (a2.flag = '*')) {
        flag = '*';
    }
    return Nas(((Des)a1 + (Des)a2), flag);
}
Nas operator-( Nas a1,  Nas a2) {
    char flag;
    if ((a1.flag = '*') || (a2.flag = '*')) {
        flag = '*';
    }
        return Nas(((Des)a1 - (Des)a2), flag);
}

Nas operator*(Nas a1, Nas a2) {
    char flag = ' ';
    if ((a1.flag = '*') || (a2.flag = '*')) {
        flag = '*';
    }
        return Nas(((Des)a1 * (Des)a2), flag);
}

Nas operator/(Nas a1, Nas a2) {
    char flag = ' ';
    if ((a1.flag = '*') || (a2.flag = '*')) {
        flag = '*';
    }
    return Nas(((Des)a1 / (Des)a2), flag);
}
