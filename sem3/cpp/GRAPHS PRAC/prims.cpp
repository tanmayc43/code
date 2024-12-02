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
        int n, m;
        cin >> n >> m;
        vector<pair<pair<int, int>, int>> v(m);
        unordered_map<int, vector<pair<int, int>>> graph;
        for (int i = 0; i < m; i++) {
            cin >> v[i].first.first >> v[i].first.second >> v[i].second;
        }
        for (int i = 0; i < m; i++) {
            graph[v[i].fi.fi].pb({v[i].fi.se, v[i].se});
            graph[v[i].fi.se].pb({v[i].fi.fi, v[i].se});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(n);
        pq.push({0, 0});
        int sum = 0;
        vector<pair<int, int>> mst_edges;
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            int node = it.se, weight = it.fi;
            if (vis[node]) continue;
            vis[node] = 1;
            sum += weight;
            if (weight != 0) mst_edges.pb({node, it.se});
            for (auto gg : graph[node]) {
                int adjnode = gg.fi, adjwt = gg.se;
                if (!vis[adjnode]) {
                    pq.push({adjwt, adjnode});
                }
            }
        }
        cout << sum << endl;
        for (auto edge : mst_edges) {
            cout << edge.fi << spc << edge.se << endl;
        }
    }
    return 0;
}
