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
        unordered_map<int, vector<int>> graph;
        for(int i=0;i<n;i++){
            int x; cin >> x;
            for(int j=0;j<x;j++){
                int g; cin >> g;
                graph[i+1].push_back(g);
            }
        }

        int adj_matrix[n][n];
        memset(adj_matrix, 0, sizeof(adj_matrix));
        for(auto it : graph){
            for(auto gg : it.second){
                adj_matrix[it.first-1][gg-1]=1;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0; j<n;j++){
                cout << adj_matrix[i][j];
            }
            cout << endl;
        }


        

    }
    return 0;
}