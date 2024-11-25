#include <stdio.h>

#define MAX 50

int p[MAX], w[MAX], n; // Arrays for profits and weights, and the number of items

int knapsack(int i, int capacity);
int max(int a, int b);

int main() {
    int capacity, optimalSolution;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the weights of the objects:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    printf("Enter the profits of the objects:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    optimalSolution = knapsack(0, capacity);

    printf("The optimal solution is: %d\n", optimalSolution);

    return 0;
}

// Recursive function to solve the knapsack problem
int knapsack(int i, int capacity) {
    if (i == n) {
        // If no items are left, return 0
        return 0;
    }

    if (w[i] > capacity) {
        // If the current item's weight exceeds capacity, skip it
        return knapsack(i + 1, capacity);
    }

    // Return the maximum of either including or excluding the current item
    return max(knapsack(i + 1, capacity), knapsack(i + 1, capacity - w[i]) + p[i]);
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}
