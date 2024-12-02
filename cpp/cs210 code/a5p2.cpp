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

bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second/p1.first > p2.second/p2.first;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n,w;
        cin >> n >>w;
        vector<pair<int,int>> v(n);
        for (auto &p : v) cin >> p.first >> p.second;
        sort(v.begin(),v.end(), comp);
        //for(auto &p : v)cout << p.first << " " << p.second << endl;
        float total_value= 0, exhausted_weight= 0, i=0;
        while(exhausted_weight<w){
            int x = w-exhausted_weight;
            if(x<v[i].first){
                total_value += ((float)(v[i].second/(float)v[i].first))*x;
                break;
            }
            total_value += v[i].second;
            exhausted_weight+=v[i].first;
            i++;
        }
        cout << total_value << endl;
    }
    return 0;
}