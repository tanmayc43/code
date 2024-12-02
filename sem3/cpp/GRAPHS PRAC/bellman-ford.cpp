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

        vector<int> dist(n+1, INT_MAX); dist[src]=0;

        for(int i=1;i<n;i++){
            for(auto it : edges){
                int u = it.first.first;
                int v = it.first.second;
                int weight = it.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        bool flag = false;
        for(auto it: edges){
            int u = it.first.first;
                int v = it.first.second;
                int weight = it.second;
                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                    flag = true;
                    break;
                }
        }
        if(flag) cout << "NEGATIVE CYCLE PRESENT" << endl;
        else for(auto it : dist) cout << it << " " ;
        cout << endl;
        
    }
    return 0;
}