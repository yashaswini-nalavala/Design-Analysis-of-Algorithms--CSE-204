#include <stdio.h>
#include <math.h>

int main() {
    double x, n, sum;

    printf("Enter x and n: ");
    scanf("%lf %lf", &x, &n);

    sum = (pow(x,  (n + 1)) - 1) / (x-1);

    printf("Sum = %.2lf", sum);

    return 0;
}