Aim : Code implement power function in O(logn) time complexity.

#include <iostream>
using namespace std;

long long SurajPower(long long x, long long n) {
    if (n == 0) return 1;
    long long half = SurajPower(x, n / 2);
    if (n % 2 == 0) return half * half;
    else return x * half * half;
}

int main() {
    long long x, n;
    cin >> x >> n;
    cout << SurajPower(x, n);
    return 0;
}
