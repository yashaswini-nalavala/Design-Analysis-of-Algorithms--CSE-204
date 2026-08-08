#include <stdio.h>

void bubbleSort(int arr[], int n)
{
    int i, j, temp;

    for (j = 1; j <= n - 1; j++)
    {
        for (i = 1; i <= n - j; i++)
        {
            if (arr[i - 1] > arr[i])
            {
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int BinarySearch(int arr[], int start, int end, int key)
{
    int mid;

    while (start <= end)
    {
        mid = (start + end) / 2;

        if (arr[mid] == key)
            return mid;

        if (arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return -1;
}

int main()
{
    int n, i, key, result;
    int arr[100];

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");

    for (i = 0; i < n; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("\nArray after sorting:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\nEnter the element to search: ");
    scanf("%d", &key);

    result = BinarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Search Found at position %d\n", result + 1);
    else
        printf("Search Not Found\n");

    return 0;
}