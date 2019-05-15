#include <iostream>
#include <string>

#include <omp.h>

#include "simd.p4.h"

void Test_Mult(float* A, float* B, float* C, int size)
{
    for (int i = 0; i < size; i++)
        C[i] = A[i] * B[i];
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
    char test_type = *argv[2];
    std::string test_label;

    float* A = new float[array_size];
    float* B = new float[array_size];
    float* C = new float[array_size];

#ifdef _DEBUG
    std::cout << array_size << std::endl;
    std::cout << "Array Multiplication Test" << std::endl;
#endif

    double time_start = omp_get_wtime();

    switch(test_type)
    {
    case 'a':
#ifdef _DEBUG
        std::cout << "Test a" << std::endl;
#endif
        Test_Mult(A, B, C, array_size);
        test_label = "Multipl.";
        break;
    case 'b':
#ifdef _DEBUG
        std::cout << "Test b" << std::endl;
#endif
        Test_Mult_SIMD(A, B, C, array_size);
        test_label = "SIMD Multipl.";
        break;
    case 'c':
#ifdef _DEBUG
        std::cout << "Test c" << std::endl;
#endif
        Test_MultReduct(A, B, array_size);
        test_label = "Multipl./Reduction";
        break;
    case 'd':
#ifdef _DEBUG
        std::cout << "Test d" << std::endl;
#endif
        test_label = "SIMD Multipl./Reduction";
        Test_MultReduct_SIMD(A, B, array_size);
        break;
    }

    double time_end = omp_get_wtime();

    std::cout << test_label << "\t" << array_size << "\t" << time_end - time_start << std::endl;

    return 0;
}
