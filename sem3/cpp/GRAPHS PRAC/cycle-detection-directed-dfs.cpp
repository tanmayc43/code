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

//undirected ka code nhi chlega coz node has to be visited again on the same path
//directed mein even if not the same path, it is possible ki since ek node visited mark hogya hai and 
//therefore undirected ke code ke according vo cycle detect kr lega

bool dfs(vector<int>& visited, vector<int>& pathvisited, unordered_map<int, vector<int>>& graph, int src){
    visited[src]=1; pathvisited[src]=1;

    for(auto it: graph[src]){
        if(!visited[it]){
            if(dfs(visited, pathvisited, graph, it)) return true;
        }
        else if (pathvisited[it]) return true;
    }

    pathvisited[src]=0;
    return false;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<pair<int,int>> v(m);
        for(int i=0;i<m;i++){
            cin >> v[i].first;
            cin >> v[i].second;
        }        
        unordered_map<int, vector<int>> graph;
        for(auto it: v){
            graph[it.first].push_back(it.second);
        }

        vector<int> visited(n,0), pathvisited(n,0);

        bool flag = false;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(dfs(visited, pathvisited, graph, i)){
                    flag= true;
                    break;
                }
            }
        }

        if(flag)cout << "cycle detected" << endl;
        else cout << " no cycle " << endl;

    }
    return 0;
}