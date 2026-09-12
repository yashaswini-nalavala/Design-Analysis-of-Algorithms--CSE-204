#include <stdio.h>

struct Item {
    int weight;
    int profit;
    float ratio;
};

int main() {
    struct Item items[100], temp;
    int n, capacity;
    int i, j;
    float totalProfit = 0.0;
    float fraction;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the weight and profit of each item:\n");

    for (i = 0; i < n; i++) {
        printf("Item %d weight: ", i + 1);
        scanf("%d", &items[i].weight);

        printf("Item %d profit: ", i + 1);
        scanf("%d", &items[i].profit);

        items[i].ratio =
            (float)items[i].profit / items[i].weight;
    }

    printf("\nEnter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    printf("\nItems sorted according to Profit/Weight ratio:\n");
    printf("Item\tWeight\tProfit\tRatio\n");

    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%.2f\n",
               i + 1,
               items[i].weight,
               items[i].profit,
               items[i].ratio);
    }

    printf("\nSelected items:\n");

    for (i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {
            capacity = capacity - items[i].weight;
            totalProfit = totalProfit + items[i].profit;

            printf("Item with weight %d: 100%% taken\n",
                   items[i].weight);
        }
        else if (capacity > 0) {
            fraction = (float)capacity / items[i].weight;

            totalProfit =
                totalProfit + items[i].profit * fraction;

            printf("Item with weight %d: %.2f%% taken\n",
                   items[i].weight,
                   fraction * 100);

            capacity = 0;
        }
    }

    printf("\nMaximum Profit = %.2f\n", totalProfit);

    return 0;
}