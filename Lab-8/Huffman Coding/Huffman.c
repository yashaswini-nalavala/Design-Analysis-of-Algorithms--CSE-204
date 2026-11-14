#include <stdio.h>

#define MAX 100

int freq[MAX], left[MAX], right[MAX], active[MAX];
char ch[MAX];
int code[MAX];

void printCodes(int node, int depth, int *total)
{
    if (left[node] == -1 && right[node] == -1)
    {
        printf("%c\t%d\t", ch[node], freq[node]);
        for (int i = 0; i < depth; i++)
            printf("%d", code[i]);
        printf("\n");

        *total += freq[node] * depth;
        return;
    }

    code[depth] = 0;
    printCodes(left[node], depth + 1, total);

    code[depth] = 1;
    printCodes(right[node], depth + 1, total);
}

int main()
{
    int n, nodes, total = 0;

    printf("Enter number of characters: ");
    scanf("%d", &n);

    if (n < 2 || n > 50)
    {
        printf("Enter between 2 and 50 characters.\n");
        return 0;
    }

    nodes = n;

    for (int i = 0; i < n; i++)
    {
        printf("Enter character and frequency: ");
        scanf(" %c %d", &ch[i], &freq[i]);

        if (freq[i] <= 0)
        {
            printf("Frequency must be positive.\n");
            return 0;
        }

        left[i] = right[i] = -1;
        active[i] = 1;
    }

    while (1)
    {
        int first = -1, second = -1;

        for (int i = 0; i < nodes; i++)
        {
            if (active[i])
            {
                if (first == -1 || freq[i] < freq[first])
                {
                    second = first;
                    first = i;
                }
                else if (second == -1 || freq[i] < freq[second])
                {
                    second = i;
                }
            }
        }

        if (second == -1)
            break;

        freq[nodes] = freq[first] + freq[second];
        left[nodes] = first;
        right[nodes] = second;
        active[nodes] = 1;

        active[first] = active[second] = 0;
        nodes++;
    }

    printf("\nCharacter\tFrequency\tHuffman Code\n");
    printCodes(nodes - 1, 0, &total);

    printf("\nTotal memory required: %d bits\n", total);
    return 0;
}