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

void dfs(stack<int>& s, vector<int>& visited, unordered_map<int, vector<pair<int, int>>>& graph, int src) {
    visited[src] = 1;
    for (auto it : graph[src]) {
        if (!visited[it.first]) dfs(s, visited, graph, it.first);
    }
    s.push(src);
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        ll n, m, src;
        cin >> n >> m >> src;
        
        vector<pair<pair<int, int>, int>> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
        }

        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < m; i++) {
            graph[edges[i].first.first].push_back({edges[i].first.second, edges[i].second});
        }

        vector<int> visited(n, 0);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) dfs(s, visited, graph, i);
        }

        vector<ll> dist(n, LL_MAX);
        dist[src] = 0;


        while (!s.empty()) {
            int u = s.top();
            s.pop();

            if (dist[u] != LL_MAX) { 
                for (auto it : graph[u]) {
                    int v = it.first, weight = it.second;
                    if (dist[u] + weight < dist[v]) {
                        dist[v] = dist[u] + weight;
                    }
                }
            }
        }

        for (auto d : dist) {
            if (d == LL_MAX) cout << "INF ";
            else cout << d << " ";
        }
        cout << endl;
    }
    return 0;
}