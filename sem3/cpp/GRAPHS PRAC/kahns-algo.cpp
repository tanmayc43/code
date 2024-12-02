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

// kinda bfs implementation
// can be used to detect cycle in a graph
// topo sort only valid for dag
// apply topo sort in a graph with cycle
// you dont get resultant array of size of number of node and therefore uk topo sort didnt happen


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
        
        vector<int>visited(n,0); vector<int> indegree(n,0);
        for(auto it: graph){
            for(auto gg : it.second){
                indegree[gg]+=1;
            }
        }

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0) q.push(i);
        }

        vector<int> res;
        while(!q.empty()){
            int x = q.front(); q.pop(); res.push_back(x);
            for(auto it: graph[x]){
                indegree[it]-=1;
                if(indegree[it]==0) q.push(it);
            }
        }

        for(auto it: res) cout << it << " ";
        cout << endl;

        

    }
    return 0;
}