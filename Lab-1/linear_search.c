#include <stdio.h>

int main()
{ 
    int n, i, pos, key;
    pos = 1;

    printf("Enter n\n");
    scanf("%d", &n);
    int A[n];

    printf("Enter elements of array\n");
    for(i = 0; i < n; i++)
    {   printf("Element %d :",i+1);
        scanf("%d", &A[i]);
    }

    printf("Enter the target element\n");
    scanf("%d", &key);

    for(i = 0; i < n; i++)
    {
        if(A[i] == key)
        {
            pos += i;
        }
    }

    if(pos == 1)
    {
        printf("Element not found");
    }
    else
    {
        printf("Element found at %d position", pos);
    }

    return 0;
}