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

void insertOrUpdate(int key) {
    int index = hash(key);

    while (hashTable[index] != -1 && hashTable[index] != key)
        index = (index + 1) % SIZE;

    if (hashTable[index] == -1)
        hashTable[index] = key;
}

int main() {
    int n;

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nFrequency of distinct elements:\n");

    for (int i = 0; i < n; i++) {
        int count = 0;

        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j])
                count++;
        }

        int index = hash(arr[i]);

        while (hashTable[index] != -1 && hashTable[index] != arr[i])
            index = (index + 1) % SIZE;

        if (hashTable[index] == -1) {
            hashTable[index] = arr[i];
            printf("%d : %d\n", arr[i], count);
        }
    }

    return 0;
}