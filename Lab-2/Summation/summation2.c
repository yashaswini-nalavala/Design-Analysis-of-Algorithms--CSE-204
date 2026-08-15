#include <stdio.h>

int main() {
    int n;
    long long x, sum = 0, term = 1;

    printf("Enter x and n: ");
    scanf("%lld %d", &x, &n);

    for (int i = 0; i <= n; i++) {
        sum += term;
        term *=  x;
    }

    printf("Sum = %lld", sum);

    return 0;
}