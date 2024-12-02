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

vector<int> dfs(int src, unordered_map<int, vector<int>> graph, int n, vector<int> &visited, vector<int> &res){
    res.push_back(src);
    visited[src]=1;
    for(auto it : graph[src]){
        if(visited[it]!=1){
            dfs(it,graph,n,visited,res);
        }
    }
    return res;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<pair<int,int>> graph(n);
        for(int i=0;i<n;i++){
            cin >> graph[i].first;
            cin >> graph[i].second;
        }

        unordered_map<int, vector<int>> g;
        for(int i=0;i<n;i++){
            g[graph[i].first].push_back(graph[i].second);
            g[graph[i].second].push_back(graph[i].first);
        }
        vector<int> res, visited(n+1);
        vector<int> fin = dfs(0,g,6,visited,res) ;
        bool present = false;
        for(int i=0;i<fin.size();i++){
            if(fin[i]==5){
                present=true;
                break;
            }
        }

        if(present) cout << "yes" << endl;
        else cout << "no" << endl;
        

        

    }
    return 0;
}