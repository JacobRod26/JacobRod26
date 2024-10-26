#include <stdio.h>
#include <stdlib.h>

float power(float base,int exponent)
{
    if(exponent == 0)
    {
        return 1;
    }
    else
    {
        return base * power(base, exponent-1);
    }

}



int main()
{
    float base;
    int exponent;

    printf("Recursive Power Function:\n");
    printf("Enter base: ");
    scanf("%f", &base);

    printf("Enter exponent: ");
    scanf("%d", &exponent);

    float result = power(base, exponent);
    printf("\nResult: %.2f", result);
    return 0;
}
