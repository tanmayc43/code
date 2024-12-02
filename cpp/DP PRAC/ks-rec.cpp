#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sz(q) (ll)(q.size())
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()
#define bac(v) v.rbegin(), v.rend()
#define uint unsigned long long;
#define forf(i,a,b) for(int i=a;i<b;i++)
#define forr(i,a,b) for(int i=a;i>b;i--)
#define endl '\n'
#define spc " "
#define precise(i) cout << fixed << setprecision(i)
#define nl cout << '\n'
#define MOD 1000000007
#define mod 998244353
#define LL_MAX LLONG_MAX
#define LL_MIN LLONG_MIN
#define ULL_MAX ULLONG_MAX

using ll = long long;
using ld = long double;
using ull = unsigned long long;

int maxprof(vector<int>& val, vector<int>& wt, ll n, ll bagwt){
    if(n==0 || bagwt ==0) return 0;

    if(wt[n-1]>bagwt) return maxprof(val,wt, n-1, bagwt);
    else{
        return max(val[n-1] + maxprof(val, wt, n-1, bagwt-wt[n-1]) , maxprof(val,wt, n-1, bagwt ));
    }
}


int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        ll n,bagwt;
        cin >> n >> bagwt;
        vector<int>wt(n), val(n);
        for(int i=0;i<n;i++)cin >> wt[i];
        for(int i=0;i<n;i++)cin >> val[i];

        cout << maxprof(val,wt,n,bagwt) << endl; 

    }
    return 0;
}