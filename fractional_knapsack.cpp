#include<bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    Item(int v, int w) : value(v), weight(w) {}
};

bool cmp(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {
    sort(items.begin(), items.end(), cmp);
    double totalValue = 0.0;

    cout << "Item selection:\n";
    for (int i = 0; i < items.size(); i++) { 
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
            cout << "Selected 100% of item with value " << items[i].value << " and weight " << items[i].weight 
                 << ", contributing value " << items[i].value << endl;
        } else {
            double fraction = (double)capacity / items[i].weight;
            double selectedValue = items[i].value * fraction;
            totalValue += selectedValue;
            cout << "Selected " << fraction * 100 << "% of item with value " << items[i].value << " and weight " << items[i].weight
                 << ", contributing value " << selectedValue << endl;
            break;
        }
    }
    return totalValue;
}

int main() {
    vector<Item> items;
    items.push_back({60,10});
    items.push_back({100,20});
    items.push_back({120,30});
    int capacity = 50;
    cout << "Maximum value in Knapsack = " << fractionalKnapsack(capacity, items) << endl;
    return 0;
}

