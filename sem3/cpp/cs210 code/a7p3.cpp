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

void dfs(unordered_map<int, vector<int>>&graph, vector<int>&visited, int src){
    visited[src]=1;
    for(auto it: graph[src]){
        if(!visited[it]) {
            dfs(graph, visited, it);
        }
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
        unordered_map<int, vector<int>> graph;
        for(auto it: v){
            graph[it.first].push_back(it.second);
            graph[it.second].push_back(it.first);
        }

        // int adj_matrix[n][n];
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cin >> adj_matrix[i][j];
        //     }
        // }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         graph[i+1].push_back(j+1);
        //         graph[j+1].push_back(i+1);
        //     }
        // }
        
        vector<int> visited(n+1);
        dfs(graph, visited, 1);
        int flag=0;
        for(int i=0;i<visited.size();i++){
            if(visited[i]==0){
                flag=1;
                break;
            }
        }
        if(flag==1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}