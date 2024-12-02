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
        int n,sum;
        cin >> n >> sum;
        vector<int>val(n);

        for(int i=0;i<n;i++)cin >> val[i];

        bool dp[n+1][sum+1]; 
        //memset(dp,-1, sizeof(dp));

        for(int i=0;i<sum+1;i++) dp[0][i]=false;
        for(int i=0;i<n+1;i++) dp[i][0]=true;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(val[i-1]<=j){
                    dp[i][j] = ((dp[i-1][j-val[i-1]]) || (dp[i-1][j]));
                }
                else dp[i][j] = dp[i-1][j];
            }
        }

        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    return 0;
}