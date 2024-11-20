#include <stdio.h>

void knapsack(int n, float weight[], float profit[], float capacity) {
    float fraction[20] = {0}, totalProfit = 0;
    float remainingCapacity = capacity;

    for (int i = 0; i < n; i++) {
        if (weight[i] <= remainingCapacity) {
            // Take the full item
            fraction[i] = 1.0;
            totalProfit += profit[i];
            remainingCapacity -= weight[i];
        } else {
            // Take a fraction of the item
            fraction[i] = remainingCapacity / weight[i];
            totalProfit += fraction[i] * profit[i];
            break; // Knapsack is full
        }
    }

    // Display result
    printf("\nFractions taken: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", fraction[i]);
    }
    printf("\nMaximum profit: %.2f\n", totalProfit);
}

void sortItems(int n, float weight[], float profit[]) {
    float ratio[20];

    // Calculate profit/weight ratio
    for (int i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items based on ratio
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratio
                float temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                // Swap weights and profits
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }
}

int main() {
    float weight[20], profit[20], capacity;
    int num;

    // Input
    printf("Enter the number of items: ");
    scanf("%d", &num);

    printf("Enter weights and profits for each item:\n");
    for (int i = 0; i < num; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%f", &capacity);

    // Sort items by profit/weight ratio
    sortItems(num, weight, profit);

    // Solve the knapsack problem
    knapsack(num, weight, profit, capacity);

    return 0;
}
