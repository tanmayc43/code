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

vector<int> cands;
int minelt(vector<int> b, int low, int high){
    if(high-low<=1) return min(b[low],b[high]);
    int mid = (low+high)/2;
    return min(minelt(b,low,mid), minelt(b,mid+1,high));
}

int maxelt(vector<int> a, int low, int high){
    if(high-low<=1) {
        cands.push_back(min(a[low],a[high]));
        return max(a[low],a[high]);
    }
    int mid = (low+high)/2;
    return max(maxelt(a,low,mid), maxelt(a,mid+1,high));
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    int y = maxelt(v,0,n-1);
    cout << minelt(cands,0,cands.size()-1);
    return 0;
}