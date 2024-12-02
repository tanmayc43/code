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

void moddfs(stack<int>& s, unordered_map<int, vector<pair<int,int>>>& graph, vector<int>& visited, int src){
    visited[src]=1;

    for(auto it: graph[src]){
        if(!visited[it.first]){
            moddfs(s, graph, visited, it.first);
        }
    }

    s.push(src);
}

void normaldfs(unordered_map<int, vector<pair<int,int>>>& graph, vector<int>& revisited, int src, vector<int>& comp){
     revisited[src]=1;
     comp.push_back(src);

    for(auto it: graph[src]){
        if(!revisited[it.first]){
            normaldfs(graph, revisited, it.first, comp);
        }
    }
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        ll n,m,src;
        cin >> n >> m >> src;
        vector<pair<pair<int,int>, int>> edges(m);
        for(int i=0;i<m;i++){
            cin >> edges[i].first.first >> edges[i].first.second >> edges[i].second;
        }

        // for(auto x : edges) {
        //     cout << x.first.first << " " << x.first.second << " " << x.second << endl;
        // }

        unordered_map<int, vector<pair<int,int>>> graph, rev_graph;
        for(auto it: edges){
            graph[it.first.first].push_back({it.first.second,it.second});
            rev_graph[it.first.second].push_back({it.first.first,it.second});
        }

        // for(auto it: graph){
        //     cout << it.first << " -> ";
        //     for(auto gg : it.second){
        //         cout << gg.first << " " << gg.second << ", ";
        //     }
        //     cout << endl;
        // }

        vector<int>visited(n,0); stack<int>s;
        vector<int> revisited(n,0);

        moddfs(s,graph,visited,src); 

        // while(!s.empty()){
        //     int x = s.top(); s.pop();
        //     cout << x << " ";
        // }

        vector<vector<int>> res;
        while(!s.empty()){
            int x = s.top(); s.pop();
            if(!revisited[x]){
                vector<int> comp;
                normaldfs(rev_graph, revisited, x, comp);
                res.push_back(comp);
            }
        }
        
    

        for(auto it: res){
            for(auto gg: it){
                cout << gg << " ";
            }
            cout << endl;
        } 
        
    }       

    return 0;
}