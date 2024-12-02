
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

void dfs(vector<int>&visited, unordered_map<int,vector<int>>&graph, int src){
    visited[src]=1;
    for(auto it : graph[src]){
        if(!visited[it]) dfs(visited, graph, it);
    }

}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].first;
            cin >> v[i].second;
        }

        unordered_map<int, vector<int>> graph, graph_rev;
        for(int i=0;i<n;i++) {
            graph[v[i].first].push_back(v[i].second);
            graph_rev[v[i].second].push_back(v[i].first);
        }

        bool flag = false;
        vector<int>visited(n+1);
        dfs(visited, graph, 1);
        for(int i=0;i<n;i++){
            
        }


        

    }
    return 0;
}
