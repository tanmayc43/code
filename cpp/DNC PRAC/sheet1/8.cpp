#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

long long complex_addtn(long long a, long long b) {
    if (a < 10 || b < 10) return a + b;
    int n = max(log10(a)+1, log10(b)+1);
    long long pow10_half_n = pow(10, n/2);

    long long h1 = a / pow10_half_n;
    long long l1 = a % pow10_half_n;
    long long h2 = b / pow10_half_n;
    long long l2 = b % pow10_half_n;

    long long hres = complex_addtn(h1, h2);
    long long lres = complex_addtn(l1, l2);
    return hres * pow10_half_n + lres;
}

int main() {
    fast;
    long long a, b;
    cin >> a >> b;
    cout << complex_addtn(a, b) << endl;

    return 0;
}
