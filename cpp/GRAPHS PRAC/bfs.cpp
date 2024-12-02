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

//saari nodes tk reach krna


// bfs
// dfs


void bfs(int src, unordered_map<int, vector<int>> graph, int n){
    queue<int> q;
    vector<int> visited(n+1);
    q.push(src);
    visited[src]=1;
    while(!q.empty()){
        int f = q.front();
        q.pop();
        cout << f << " ";
        for(auto gg : graph[f]){
            if(visited[gg]!=1){
                q.push(gg);
                visited[gg]=1;
            }
        }
    }
    cout << endl;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].first;
            cin >> v[i].second;
        }

        unordered_map<int, vector<int>> graph;
        for(int i=0;i<n;i++){
            graph[v[i].first].push_back(v[i].second);
            graph[v[i].second].push_back(v[i].first);
        }
        
        // for(auto it: graph){
        //     cout << it.first << " -> ";
        //     for(auto gg : it.second){
        //         cout << gg << " ";
        //     }
        //     cout << endl;
        // }

        bfs(0, graph, 5);
    }
    return 0;
}