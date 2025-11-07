#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int weight;
    int value;

    Item(int w, int v) : weight(w), value(v) {}
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items) {
    sort(items.begin(), items.end(), compare);

    double maxValue = 0.0; 
    int currentWeight = 0; 

    cout << "\nItems selected (weight, value, fraction taken):\n";

    for (auto &item : items) {
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            maxValue += item.value;
            cout << "Item(weight=" << item.weight 
                 << ", value=" << item.value 
                 << ", fraction=1)\n";
            if(currentWeight == W)  break;
        } else {
            int remainingWeight = W - currentWeight;
            double fraction = (double)remainingWeight / item.weight;
            maxValue += item.value * fraction;
            cout << "Item(weight=" << item.weight 
                 << ", value=" << item.value 
                 << ", fraction=" << fraction << ")\n";
            break;
        }
    }

    return maxValue;
}

int main() {
    int W, n;
    
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;

    for (int i = 0; i < n; i++) {
        int weight, value;
        cout << "Enter weight and value for item " << i + 1 << ": ";
        cin >> weight >> value;
        items.push_back(Item(weight, value));
    }

    double maxVal = fractionalKnapsack(W, items);

    cout << "\nMaximum value in the knapsack: " << maxVal << endl;

    return 0;
}
