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


int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> cookies(n), greed(n);
        for(int i=0;i<n;i++) cin >> cookies[i];
        for(int i=0;i<n;i++) cin >> greed[i];
        sort(cookies.begin(), cookies.end());
        sort(greed.begin(), greed.end());
        int res=0, i=0, j=0;
        while(i<n && j<n){
            if(greed[i]<=cookies[j]){
                res+=1;
                i+=1;
            }
            j+=1;
        }
        cout << res << endl;
    }
    return 0;
}