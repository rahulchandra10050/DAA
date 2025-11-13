Aim: Develop a program and analyze complexity to find all occurrences of a pattern P in a given stringS.

#include <iostream>
#include <string>
using namespace std;

void SurajPatternSearch(string S, string P) {
    int n = S.length(), m = P.length();
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (S[i + j] != P[j]) break;
        if (j == m) cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    string S, P;
    cout << "Enter text: ";
    cin >> S;
    cout << "Enter pattern: ";
    cin >> P;
    SurajPatternSearch(S, P);
    cout << "Time Complexity: O((n - m + 1) * m)\n";
    cout << "Space Complexity: O(1)\n";
    return 0;
}
