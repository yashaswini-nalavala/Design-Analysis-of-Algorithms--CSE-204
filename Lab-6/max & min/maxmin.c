#include <stdio.h>

struct Result {
    int max;
    int min;
};

struct Result findMaxMin(int a[], int low, int high) {
    struct Result r, left, right;
    int mid;

    if (low == high) {
        r.max = a[low];
        r.min = a[low];
        return r;
    }

    if (high == low + 1) {
        if (a[low] > a[high]) {
            r.max = a[low];
            r.min = a[high];
        } else {
            r.max = a[high];
            r.min = a[low];
        }
        return r;
    }

    mid = (low + high) / 2;

    left = findMaxMin(a, low, mid);
    right = findMaxMin(a, mid + 1, high);

    r.max = (left.max > right.max) ? left.max : right.max;
    r.min = (left.min < right.min) ? left.min : right.min;

    return r;
}

int main() {
    int n, i;
    int a[100];
    struct Result result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    result = findMaxMin(a, 0, n - 1);

    printf("\nArray: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\n\nMaximum element = %d", result.max);
    printf("\nMinimum element = %d\n", result.min);

    return 0;
}