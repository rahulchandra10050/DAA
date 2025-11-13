Aim: Develop a program and analyze complexity to implement subset-sum problem using Dynamic Programming.

#include <iostream>
using namespace std;

bool SurajSubsetSum(int arr[], int n, int sum) {
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++) dp[i][0] = true;
    for (int j = 1; j <= sum; j++) dp[0][j] = false;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }
    return dp[n][sum];
}

int main() {
    int n, sum;
    cin >> n >> sum;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (SurajSubsetSum(arr, n, sum))
        cout << "Subset with given sum exists\n";
    else
        cout << "Subset with given sum does not exist\n";
    cout << "Time Complexity: O(n * sum)\n";
    cout << "Space Complexity: O(n * sum)\n";
    return 0;
}
