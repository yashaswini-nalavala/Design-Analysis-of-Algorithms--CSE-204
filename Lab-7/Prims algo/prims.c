#include <stdio.h>

int main()
{
    int n;
    int cost[20][20];
    int visited[20] = {0};
    int i, j;
    int edges = 0;
    int min, u = 0, v = 0;
    int total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    visited[0] = 1;

    printf("\nEdges in MST:\n");

    while (edges < n - 1)
    {
        min = 9999;

        for (i = 0; i < n; i++)
        {
            if (visited[i] == 1)
            {
                for (j = 0; j < n; j++)
                {
                    if (visited[j] == 0 && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", u, v, min);

        total = total + min;
        visited[v] = 1;
        edges++;
    }

    printf("Minimum Cost = %d\n", total);

    return 0;
}