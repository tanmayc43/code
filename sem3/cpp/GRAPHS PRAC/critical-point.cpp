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


int currtime;

void dfs(int node, int parent, unordered_map<int, vector<int>>& graph, vector<int>& visited, vector<int>& intime, vector<int>& lowest, vector<int>& mark) {
    visited[node] = 1;
    intime[node] = lowest[node] = currtime++;
    int child=0;
    for (int neighbor : graph[node]) {
        if (neighbor == parent) continue;
        if (!visited[neighbor]) {
            dfs(neighbor, node, graph, visited, intime, lowest, mark);
            lowest[node] = min(lowest[node], lowest[neighbor]);
            if (lowest[neighbor] >= intime[node] && parent!=-1) {
                mark[node]=1;
            }
            child+=1;
        } 
        else lowest[node] = min(lowest[node], intime[neighbor]);
    }
    if(child>1 && parent == -1) mark[node]=1;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, src;
        cin >> n >> m >> src;

        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> visited(n, 0), intime(n, 0), lowest(n, 0);
        vector<pair<int, int>> res;  vector<int>mark(n);
        currtime = 1;

        for (int i = 0; i <n; i++) {
            if (!visited[i]) {
                dfs(i, -1, graph, visited, intime, lowest, mark);
            }
        }


        for (auto edge : res) {
            cout << edge.first << " " << edge.second << endl;
        }

        for (int i=0;i<n;i++) {
            if(mark[i]==1) cout << i << " ";
        }
        cout << endl;


    }
    return 0;
}