#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()
using ll = long long;

int find(int u, vector<int>& parent) {
    if (u != parent[u]) parent[u] = find(parent[u], parent);
    return parent[u];
}

bool unite(int u, int v, vector<int>& parent, vector<int>& rank) {
    int pu = find(u, parent), pv = find(v, parent);
    if (pu == pv) return false;
    if (rank[pu] < rank[pv]) swap(pu, pv);
    parent[pv] = pu;
    if (rank[pu] == rank[pv]) rank[pu]++;
    return true;
}

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, pair<int, int>>> edges(m);
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = {w, {u, v}};
        }
        
        sort(all(edges));
        vector<int> parent(n), rank(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
        ll sum = 0;
        vector<pair<int, int>> mst_edges;
        for (auto &[w, uv] : edges) {
            if (unite(uv.fi, uv.se, parent, rank)) {
                sum += w;
                mst_edges.pb({uv.fi, uv.se});
            }
        }
        cout << sum << endl;
        for (auto &[u, v] : mst_edges) {
            cout << u << " " << v << endl;
        }
    }
    return 0;
}
