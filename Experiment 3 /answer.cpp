Aim : Code to find frequency of elements in a given array in O(N) time complexity.


#include <iostream>
#include <unordered_map>
using namespace std;

void SurajFrequency(int arr[], int n) {
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++) freq[arr[i]]++;
    for (auto x : freq) cout << x.first << " -> " << x.second << endl;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    SurajFrequency(arr, n);
    return 0;
}
