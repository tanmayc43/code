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

// adjacency matrix
// adjacency list
 


int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n,lim;
        cin >> n >> lim;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++) {
            cin >> v[i].first;
            cin >> v[i].second;
        }

        int adj_mat[lim][lim];
        // for(int i=0;i<lim;i++){
        //     for(int j=0;j<lim;j++){
        //         adj_mat[i][j]=0;
        //     }
        // }


        memset(adj_mat, 0, sizeof(adj_mat) );

        for(int i=0;i<n;i++){
            adj_mat[v[i].first][v[i].second]=1;
            adj_mat[v[i].second][v[i].first]=1;
        }

        for(int i =0;i<lim;i++){
            for(int j=0;j<lim;j++){
                cout << adj_mat[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        

    }
    return 0;
}