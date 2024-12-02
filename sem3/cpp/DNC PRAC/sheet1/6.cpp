#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

long long karatsuba(long long a, long long b){
    if (a < 10 || b < 10) return a*b;
    int n = max(to_string(a).length(), to_string(b).length());
    int n2 = n / 2;

    long long x = a / (long long)pow(10, n2);
    long long y = a % (long long)pow(10, n2);
    long long z = b / (long long)pow(10, n2);
    long long w = b % (long long)pow(10, n2);

    long long p = karatsuba(x, z);
    long long q = karatsuba(x + y, z + w);
    long long r = karatsuba(y, w);

    return (long long)pow(10, 2*n2)*p + (long long)pow(10, n2)*(q-p-r) + r;
}

int main(){
    fast;
    long long a, b;
    cin >> a >> b;
    cout << karatsuba(a, b) << endl;
    return 0;
}

