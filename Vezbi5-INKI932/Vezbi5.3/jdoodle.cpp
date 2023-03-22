#include <iostream>
#include <cmath>

using namespace std;

int Add(const void *num1, const void *num2)
{
    const int *a = static_cast<const int *>(num1);
    const int *b = static_cast<const int *>(num2);
    return *a + *b;
}

int Subtract(const void *num1, const void *num2) 
{
    const int *a = static_cast<const int *>(num1);
    const int *b = static_cast<const int *>(num2);
    return *a - *b;
}

float Divide(const void *num1, const void *num2) 
{
    const int *a = static_cast<const int *>(num1);
    const int *b = static_cast<const int *>(num2);
    return static_cast<float>(*a) / static_cast<float>(*b);
}

double Power(const void *num1, const void *num2) 
{
    const int *a = static_cast<const int *>(num1);
    const int *b = static_cast<const int *>(num2);
    return pow(*a, *b);
}

void Calculate(void *result, const void *num1, const void *num2, int (*func)(const void *, const void *)) 
{
    int *r = static_cast<int *>(result);
    *r = (*func)(num1, num2);
}

void Calculate(void *result, const void *num1, const void *num2, float (*func)(const void *, const void *))
{
    float *r = static_cast<float *>(result);
    *r = (*func)(num1, num2);
}

void Calculate(void *result, const void *num1, const void *num2, double (*func)(const void *, const void *)) 
{
    double *r = static_cast<double *>(result);
    *r = (*func)(num1, num2);
}

int main()
{
    int A = (int)'A', T = (int)'T';
    int result;
    float fresult;
    double dresult;
    
    Calculate(&result, &A, &T, &Add);
    cout << A << " + " << T << " = " << result <<endl;
    
    Calculate(&result, &A, &T, &Subtract);
    cout << A << " - " << T << " = " << result <<endl;
    
    Calculate(&fresult, &A, &T, &Divide);
    cout << A << " / " << T << " = " << fresult <<endl;
    
    Calculate(&dresult, &A, &T, &Power);
    cout << A << " ^ " << T << " = " << dresult <<endl;
}
