#include "Nas.h"
#include <iostream> 
#include "matrix.h"
#include "matrica.h"
#include "vector.h"

void main(void) {
    /*  std::vector<float> input1 = {20.2, 30.3 , 555.2 ,325.8, 155.3};
      std::vector<float> input2 = { -32.32, 995.42, 2000.2, 2, 3.212 };
      std::vector<float> input3 = { 1, 2, 3.2 }, input4 = { 1, 2 };
      vector v1(input1);
      vector v2(input2);
      vector v3(input3);
      vector v4(input4);*/

    std::vector<std::vector<float>> data1 = { {1, 2}, {3, 4}, {10,11} };
    std::vector<std::vector<float>> data2 = { {5, 6}, {7, 8},{12,13} };

    matrix mat1(data1);
    matrix mat2(data2);
    mat1.print();
    mat1 = mat2;
    printf("=\n");
    mat2.print();
    printf("+\n");
    matrix mat3 = mat1 + mat2;
    mat3.print();
    printf("==\n");
    mat1 == mat3 ? printf("T") : printf("F");


    //двойные указатели
    std::vector<std::vector<float>> a = { {1.1, 2.2}, {4.4, 5.5} };
    std::vector<std::vector<float>> b = { {6.6, 7.7}, {8.8, 9.9} };
    matrica mac1(a);
    matrica mac2(b);
    printf("pypy\n");
    mac1.print();
    printf("\n=");
    matrica mac3;
    mac3 = mac2;
    mac3.print();
    printf("\n+");
    mac3 = mac1 + mac2;
    mac3.print();
    printf("\n==");
    mat1 == mat3 ? printf("T") : printf("F");

}

    
 /* v3 == v4 ? printf("T") : printf("F");
    vector v5(v4);
    printf("\nv1:\n\n");
    v1.print();
    printf("\nv2:\n\n");
    v2.print();
    vector sum = v1 + v2;
    printf("\nsum:\n\n");
    sum.print();
    vector add = v1;
    add += v2;//???
    printf("\nadd:\n\n");
    add.print();
    vector dif = v1 - v2;
    printf("\ndif:\n\n");
    dif.print();
    v1 = v2;
    printf("\n============================\n\n");
    v1.print();
    printf("============================\n\n");
    v2.print();
    printf("============================\n");
    v1 == v2 ? printf("T") : printf("F");
}*/