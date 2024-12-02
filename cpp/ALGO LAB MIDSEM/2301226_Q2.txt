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



int maxsum(vector<int>&a, int l, int h){
    if(l==h) return a[l] ;
    int mid = (l+h)/2;
    int lres = maxsum(a, 0, mid );
    int rres = maxsum(a,mid+1,h);

    int left_sum=INT_MIN, lcurrsum=0;
    for(int i=mid;i>=0;i--){
        lcurrsum+=a[i];
        if(lcurrsum>left_sum)left_sum=lcurrsum;
    }
 
    int right_sum=INT_MIN, rcurrsum=0;
    for(int i=mid+1;i<=h;i++){
        rcurrsum+=a[i];
        if(rcurrsum>right_sum)right_sum=rcurrsum;  
    }

    int g= max(lres,rres);
    return max(g, left_sum+right_sum);
}

int perfectop(vector<int>&v){
    int maxneg=v[0];
    for(int i=1;i<v.size();i++){
        if(v[i]<v[maxneg]) maxneg=i;
    }
    if(v[maxneg]<0) return maxneg;
    else return -1;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        int g = perfectop(v);
        vector<int> updated;
        if(g==-1) cout << maxsum ( v, 0,n-1) << endl;
        else{
            for(int i=0;i<n;i++){
                if(i!=g){
                    updated.push_back(v[i]);
                }
            }
            cout << maxsum (updated,0,n-2);

        }
    }
    return 0;
}