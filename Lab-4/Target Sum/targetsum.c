#include <stdio.h>

#define SIZE 100

int hashTable[SIZE];

void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

int hash(int key) {
    return (key % SIZE + SIZE) % SIZE;
}

int search(int key) {
    int index = hash(key);
    int start = index;

    while (hashTable[index] != -1) {
        if (hashTable[index] == key)
            return 1;

        index = (index + 1) % SIZE;

        if (index == start)
            break;
    }

    return 0;
}

void insert(int key) {
    int index = hash(key);

    while (hashTable[index] != -1)
        index = (index + 1) % SIZE;

    hashTable[index] = key;
}

int main() {
    int n, T;

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter target T: ");
    scanf("%d", &T);

    for (int i = 0; i < n; i++) {
        int complement = T - arr[i];

        if (search(complement)) {
            printf("Yes, two elements exist whose sum is %d\n", T);
            printf("Elements: %d and %d\n", complement, arr[i]);
            return 0;
        }

        insert(arr[i]);
    }

    printf("No, such two elements do not exist\n");

    return 0;
}