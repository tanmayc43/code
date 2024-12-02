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
        ll n,a,b,c,d,p,q,y;
        cin >> n >> a >> b >> c >> d >> p >> q >> y;
        vector <ll> v(n+2);
        for(ll i=1;i<=n;i++) {
            ll x;
            cin >> x;
            v[i]=x+1002;
        }
        ll timeab = abs(v[b] - v[a]) * p;
        ll timeac = abs(v[c] - v[a]) * p;
        ll timebd = abs(v[d]-v[b])*p;
        if(timeac<=y){
            ll tottime = y;
            tottime+= abs(v[c]-v[d])*q;
            tottime+=timebd;
            cout << min(tottime, timeab) << endl;
        }
        else cout << timeab << endl;

    }
    return 0;
}