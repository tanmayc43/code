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

vector<vector<int>>dp;

int secmax(vector<vector<int>> dp, int y){
    int maxm = INT_MIN;
    for(int i=0;i<dp[y].size();i++){
        if(dp[y][i]>maxm) maxm= dp[y][i];
    }
    return maxm;
}

int maxelt(vector<vector<int>> &dp, vector<int> &a, int low, int high){
    if(high-low==1){
        dp[low].push_back(a[high]);
        dp[high].push_back(a[low]);
        return a[low] > a[high] ? low : high;
    }
    if(high-low==0)return high;
    int mid = (low + high) / 2;
    int left_max = maxelt(dp, a, low, mid);
    int right_max = maxelt(dp, a, mid + 1, high);
    dp[left_max].push_back(a[right_max]);
    dp[right_max].push_back(a[left_max]);
    
    return a[left_max] > a[right_max] ? left_max : right_max;
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<int> v(n);
    dp.resize(n); 
    for(int i=0;i<n;i++) cin >> v[i];
    int y = maxelt(dp,v,0,n-1);
    // dp.resize(n);
    cout << v[y]<< endl;
    cout << secmax(dp, y) << endl;
    return 0;
}