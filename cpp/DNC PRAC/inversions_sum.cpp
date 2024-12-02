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

int summation(vector<int>&v, int low, int high){
    int res=0;
    for(int i=low;i<=high;i++) res+=v[i];
    return res;
}

int merge_cnt(vector<int>&v, int low, int mid, int high){
    int res=0, i=low, j=mid+1;
    vector<int> buff;
    while(i<=mid && j<=high){
        if(v[i]>v[j]){
            res+=summation(v,i,mid) + ((mid-i+1)*v[j]);
            buff.push_back(v[j]);
            j+=1;
        }
        else{
            buff.push_back(v[i]);
            i+=1;
        }
    }

    while (i <= mid) {
        buff.push_back(v[i]);
        i+=1;
    }

    while (j <= high) {
        buff.push_back(v[j]);
        j+=1;
    }

    for (int k = low; k <= high; k++) v[k] = buff[k - low];
    return res;
}
    
int inversions_cnt(vector<int> &v, int low, int high){
    if(high==low) return 0;
    int mid = low + (high-low)/2;
    
    int left_inversions = inversions_cnt(v,low, mid);
    int right_inversions = inversions_cnt(v,mid+1,high);

    int res = left_inversions+right_inversions;
    res+= merge_cnt(v,low,mid,high);
    return res;
}


int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++)cin >> v[i];
        cout << inversions_cnt(v,0,n-1);

    }
    return 0;
}