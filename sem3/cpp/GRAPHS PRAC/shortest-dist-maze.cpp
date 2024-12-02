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
        vector<vector<int>> arr(n, vector<int>(m));
        pair<int, int> src, dest;
        cin >> src.first >> src.second >> dest.first >> dest.second;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[src.first][src.second] = 0;

        int xdir[] = {-1, 1, 0, 0};
        int ydir[] = {0, 0, -1, 1};

        queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {src.first, src.second}});
        while (!pq.empty()) {
            auto x = pq.front(); pq.pop();
            int dist_curr = x.first;
            int xc = x.second.first;
            int yc = x.second.second;

            for (int i = 0; i < 4; i++) {
                int new_x = xc + xdir[i];
                int new_y = yc + ydir[i];
                if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && arr[new_x][new_y] == 1) {
                    if (dist[xc][yc] + 1 < dist[new_x][new_y]) {
                        dist[new_x][new_y] = dist[xc][yc] + 1;
                        pq.push({dist[new_x][new_y], {new_x, new_y}});
                    }
                }
            }
        }

        if (dist[dest.first][dest.second] == INT_MAX) {
            cout << -1 << endl; 
        } else {
            cout << dist[dest.first][dest.second] << endl; 
        }
    }
    return 0;

}