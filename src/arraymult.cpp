#include <iostream>
#include <string>

#ifdef SIMD
#include "simd.p4.h"
#endif

/*
void Test_Mult()
void Test_Mult_SIMD()
void Test_MultReduct()
void Test_MultReduct_SIMD()
*/

float Test_Mult(float* A, float* B, float* C, int size)
{
    for (int i = 0; i < size; i++)
        C[i] = A[i] * B[i];
    return 
}

void Test_Mult_SIMD(float* A, float* B, float* C, int size)
{
    return SimdMul(A, B, C, size);
}

float Test_MultReduct(float* A, float* B, int size)
{
    float sum = 0;
    for (int i = 0; i < size; i++)
        sum += A[i] * B[i];

    return sum;
}

float Test_MultReduct_SIMD(float* A, float* B, int size)
{
    return SimdMulSum(A, B, size);
}

int main(int argc, char* argv[])
{
    int array_size = std::stoi(argv[1]);
    int test_type = argv[2]

    float* A = new float[array_size];
    float* B = new float[array_size];

    std::cout << "Array Multiplication Test" << std::endl;

    switch(test_type)
    {
    case 'a':
        Test_Mult(A, B, C, array_size);
        break;
    case 'b':
        Test_Mult_SIMD(A, B, C, array_size);
        break;
    case 'b':
        Test_MultReduct(A, B, array_size);
        break;
    case 'c':
        Test_MultReduct_SIMD(A, B, array_size);
        break;
    }
}
