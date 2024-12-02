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
        int n, cost;
        cin >> n >> cost;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        bool possible = true;
        int cnt5=0, cnt10=0;
        for(int i=0;i<n;i++){
            if(v[i]- cost==0) {
                cnt5+=1;
                continue;
            }
            else if (v[i]-cost==5){
                cnt10+=1;
                if(cnt5==0){
                    possible=false;
                    break;
                }
                cnt5-=1;
                continue;
            }
            else{
                if(cnt5>=3){
                    cnt5-=3;
                    continue;
                }
                else if(cnt5>=1 && cnt10>=1){
                    cnt5-=1;
                    cnt10-=1;
                    continue;
                }
                else{
                    possible=false;
                    break;
                }
            }
        }

    if(possible) cout << "true" << endl;
    else cout << "false" << endl;
        

    }
    return 0;
}