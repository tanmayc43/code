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

bool comp(const pair<int,int>&a, const pair<int,int>&b){
    return a.second < b.second;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            int start,end;
            cin >> start >> end;
            pair<int,int> p = {start,end};
            v[i]=p;
        }
        // sort(v.begin(),v.end(),[](const pair<int,int> &a, const pair<int,int> &b){
        //     return a.second < b.second;
        // });

        sort(v.begin(),v.end(),comp);

        // for(int i=0;i<n;i++){
        //     cout << v[i].first << " " << v[i].second << endl;
        // }
        
        int cnt=1, curr_end_time = v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first>=curr_end_time){
                cnt+=1;
                curr_end_time=v[i].second;
            }
        }
        cout << cnt << endl;

    }
    return 0;
}