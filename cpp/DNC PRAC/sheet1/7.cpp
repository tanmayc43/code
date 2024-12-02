#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

long long kakarot_mult(int a,int b){
    if(a<10) return a*b;
    long long h = max(a,b);
    int l=min(a,b), n = to_string(h).length();
    long long x = h / (long long)pow(10, n/2);
    long long y = h % (long long)pow(10, n/2);

    long long hres=kakarot_mult(x,b), lres=kakarot_mult(y,b);
    return hres*(long long)pow(10,n/2) + lres;
}

int main() {
    fast;
    long long a,b;
    cin >> a >> b;
    int x = max(a,b), y=min(a,b);
    cout << kakarot_mult(x,y);
    return 0;
}