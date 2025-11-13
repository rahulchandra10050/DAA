Aim: Develop a program and analyze complexity to implement 0-1 Knapsack using Dynamic Programming.

#include <iostream>
using namespace std;

int SurajKnapsack(int W, int wt[], int val[], int n) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    cin >> n >> W;
    int val[n], wt[n];
    for (int i = 0; i < n; i++) cin >> val[i];
    for (int i = 0; i < n; i++) cin >> wt[i];
    cout << "Maximum value: " << SurajKnapsack(W, wt, val, n) << endl;
    cout << "Time Complexity: O(n * W)\n";
    cout << "Space Complexity: O(n * W)\n";
    return 0;
}
