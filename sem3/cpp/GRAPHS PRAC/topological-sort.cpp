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

// only works in dag
// cycle hogi toh ordering duck ho jaegi
// undirected hoga ordering dont make no sense


void dfs(stack<int>& s, vector<int>& visited, unordered_map<int, vector<int>>& graph, int src){
    visited[src]=1;
    for(auto it : graph[src]){
        if(!visited[it]) dfs(s,visited,graph, it);
    }
    s.push(src);
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        ll n,m;
        cin >> n >> m;
        vector<pair<int,int>> edges(m);
        for(int i=0;i<m;i++){
            cin >> edges[i].first >> edges[i].second;
        }

        unordered_map<int, vector<int>> graph;
        for(int i=0;i<m;i++){
            graph[edges[i].first].push_back(edges[i].second);
        }
        vector<int>visited(n,0);
        stack<int> s;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(s,visited,graph,i);
            }
        }

        vector<int> res;
        while(!s.empty()){
            res.push_back(s.top());
            s.pop();
        }

        for(auto it: res) cout << it << " ";
        cout << endl;

    }
    return 0;
}