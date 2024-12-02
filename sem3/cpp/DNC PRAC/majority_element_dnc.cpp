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

int cnt(int low, int high, vector<int>v, int key){
    int cnt=0;
    for(int i=low;i<=high;i++){
        if(v[i]==key)cnt+=1;
    }
    return cnt;
}
int solve(int low, int high, vector<int> v) {
    if(low==high)return v[low];

    int mid = low + (high-low)/2;
    int left_major = solve(low,mid,v);
    int right_major = solve(mid+1,high,v);

    if(left_major==right_major) return left_major;
    else{
        if(cnt(low,mid,v,left_major) > cnt(mid+1,high,v,right_major)) return left_major;
        else return right_major;
    }
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int>v(n);
        for (auto &x : v) cin >> x;
        int possible_res = solve(0,n-1,v);
        if(cnt(0,n-1,v,possible_res) >= n/2 + 1) cout << possible_res << endl;
        else cout << -1 << endl;
        

    }
    return 0;
}