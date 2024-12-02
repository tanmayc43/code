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

int dp[5][8]; 


int maxprof(vector<int>& val, vector<int>& wt, int n, int bagwt){
    if (n == 0 || bagwt == 0) return dp[n][bagwt] = 0;
    if(dp[n][bagwt]!=-1) return dp[n][bagwt];

    if(wt[n-1]>bagwt) return dp[n][bagwt] = maxprof(val,wt, n-1, bagwt);
    else{
        return dp[n][bagwt]= max(val[n-1] + maxprof(val, wt, n-1, bagwt-wt[n-1]) , maxprof(val,wt, n-1, bagwt ));
    }
}


int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n,bagwt;
        cin >> n >> bagwt;
        vector<int>wt(n), val(n);
        memset(dp,-1, sizeof(dp));

        for(int i=0;i<n;i++)cin >> wt[i];
        for(int i=0;i<n;i++)cin >> val[i];

        maxprof(val, wt, n, bagwt);

        for(int i=0;i<5;i++){
            for(int j=0;j<8;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }




    }
    return 0;
}