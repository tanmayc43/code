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


bool dfs(int src, int colour, vector<int>&color, unordered_map<int, vector<int>> &graph){
    color[src]=colour;
    
    for(auto it: graph[src]){
        if(color[it]==-1){
            dfs(it,!colour, color, graph);
        }
        else if(color[it]==colour) return false;
    }
    return true;

}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        ll n,m, src;
        cin >> n >> m >> src;

        vector<pair<int,int>> edges(m);
        for(int i=0;i<m;i++){
            cin >> edges[i].first >> edges[i].second;
        }

        unordered_map<int, vector<int>> graph;
        for(int i=0;i<m;i++){
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        vector<int> color(n+1, -1); 

        bool flag = true;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(dfs(i,0, color, graph) == false){
                    flag=false;
                    break;
                }
            }
        }
        
        if(flag) cout << "BIPARTITE GRAPH" << endl;
        
    }
    return 0;
}