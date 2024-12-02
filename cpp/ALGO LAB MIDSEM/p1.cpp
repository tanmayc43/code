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

bool comp ( const pair<pair<int,int>, int> &a, const pair<pair<int,int>,int> &b){
    return a.first.second < b.first.second;
}


pair<int,int> check(pair<pair<int,int>, int> &a, vector<int>&v){
    vector<int>res;
    int i=0;
    while(v[i]<a.first.first)i+=1;
    while(v[i]<=a.first.second && v[i]>=a.first.first){
        res.push_back(v[i]);
        i+=1;
    }
    pair<int,int> p = {res[0], res[res.size()-1]};
    return p;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin >> v[i];

        vector<pair<pair<int,int>, int>> pts(m);
        for(int i=0;i<m;i++){
            cin >> pts[i].first.first;
            cin >> pts[i].first.second;
            pts[i].second = i+1;
        }

        sort(pts.begin(), pts.end(), comp);

        // for(int i=0;i<m;i++){
        //     cout << pts[i].first.first << " " << pts[i].first.second << " " << pts[i].second << endl;
        // }

        // aise solve krna hai sucht that  minimum number of points such that any random interval chosen contains atleast one of the points in that minimum collection and not the other way
    
        vector<int> res;
        pair<int,int> idk = check(pts[0],v);
        res.push_back(idk.second);
        for(int i=0;i<m;i++){
            idk = check(pts[i],v);
            // cout << buf[0]<< " " << buf[buf.size()-1] << endl;
            if(idk.first>res[res.size()-1]) res.push_back(idk.second);
        }

        for(int i=0;i<res.size();i++)cout << res[i] << " ";
        cout << endl;


    }
    return 0;
}