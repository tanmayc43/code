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

vector<vector<int>> coords = {{-1,-2},{-1,2},{1,-2},{1,2},{-2,-1},{-2,1},{2,-1},{2,1}};

int helper(int src_x, int src_y, int target_x, int target_y, int n){
    vector<vector<int>> visited(n,vector<int>(n));
    queue<pair<int,int>>q;
    q.push({src_x,src_y});
    visited[src_x][src_y]=1;
    int cnt=0;
    while(!q.empty()){
        int qsize = q.size();
        while(qsize>0){
            pair<int,int> f = q.front();
            q.pop();
            int x = f.first, y=f.second;
            if(x==target_x && y==target_y) return cnt;
            for(int k=0;k<coords.size();k++){
                int new_x = x + coords[k][0];
                int new_y = y + coords[k][1];
                if(new_x>=0 && new_y>=0 && new_x<n && new_y<n && visited[new_x][new_y]==0){
                    visited[new_x][new_y]=1;
                    q.push({new_x, new_y});
                }
            }
            qsize-=1;
        }
        cnt+=1;
    }
    return -2;
}

bool bfs(pair<int,int> src, unordered_map<pair<int,int>, vector<pair<int,int>> graph, int n, pair<int,int> target){
    queue<pair<int,int>> q;
    //vector<pair<int,int>> visited(n+1);
    q.push(src);
    //visited[src]=1;
    while(!q.empty()){
        pair<int,int> f = q.front();
        q.pop();
        //cout << f << " ";
        for(auto gg : graph[f]){
            
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
        

    }
    return 0;
}