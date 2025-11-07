#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Item {
    int value;
    int weight;
};

// Function to solve the 0/1 Knapsack problem using dynamic programming
int knapsack(int capacity, vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    // Build the dp table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w],
                               items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // --- Backtracking to find which items were included ---
    int res = dp[n][capacity];
    int w = capacity;

    cout << "\nItems selected (weight, value):\n";
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == dp[i - 1][w]) {
            // Item not included
            continue;
        } else {
            // Item included
            cout << "Item(weight=" << items[i - 1].weight
                 << ", value=" << items[i - 1].value << ")\n";

            // Subtract value and weight for next iteration
            res -= items[i - 1].value;
            w -= items[i - 1].weight;
        }
    }

    return dp[n][capacity]; // Maximum profit for the given capacity
}

int main() {
    int n, capacity;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items(n);
    
    for (int i = 0; i < n; i++) {
        cout << "Enter the profit and weight of item " << i + 1 << ": ";
        cin >> items[i].value >> items[i].weight;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    int maxProfit = knapsack(capacity, items);
    
    cout << "\nThe maximum profit is: " << maxProfit << endl;

    return 0;
}
