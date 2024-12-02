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
        int n,m,src;
        cin >> n >> m >> src;
        vector<pair<pair<int,int>, int>> edges(m);
        for(int i=0;i<m;i++){
            cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
        }

        // for(auto x : edges) {
        //     cout << x.first.first << " " << x.first.second << " " << x.second << endl;
        // }

        unordered_map<int, vector<pair<int,int>>> graph;
        for(auto it: edges){
            graph[it.first.first].push_back({it.first.second,it.second});
        }

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[src.first][src.second] = 0;

        int xdir[] = {-1, 1, 0, 0};
        int ydir[] = {0, 0, -1, 1};
        vector<int> dist(n, INT_MAX); dist[src]=0;
        // vector<int> parent(n);
        // for(int i=0;i<n;i++) parent[i]=i;

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({dist[src], src});

        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();

            if(x.first > dist[x.second]) continue;

            for(auto it : graph[x.second]){
                int v = it.first, wt = it.second; 
                if (dist[x.second] + wt < dist[v]) {
                    dist[v] = dist[x.second] + wt;
                    // parent[v] = x.second;
                    pq.push({dist[v], v});
                }
            }
        }


        for(auto x : dist) cout << x << " ";
        cout << endl;

        // for(auto x : parent) cout << x << " ";
        // cout << endl;


        

    }
    return 0;
}


