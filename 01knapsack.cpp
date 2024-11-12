#include <bits/stdc++.h>
using namespace std;

int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int> > K(n + 1, vector<int>(W + 1));

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    cout << "\nDP Table:\n";
    cout << setw(8) << "weight";
    for (w = 0; w <= W; w++)
        cout << setw(3) << w;
    cout << "\nitem\n";

    for (i = 0; i <= n; i++) {
        cout << setw(5) << i << " ";
        for (w = 0; w <= W; w++) {
            cout << setw(3) << K[i][w];
        }
        cout << endl;
    }

    return K[n][W];
}

int main()
{
    int profit[] = { 2, 4, 7,10 };
    int weight[] = { 1, 3,5,7  };
    int W = 8;
    int n = sizeof(profit) / sizeof(profit[0]);

    int maxProfit = knapSack(W, weight, profit, n);

    cout << "\nMaximum Profit: " << maxProfit << endl;

    return 0;
    
}

