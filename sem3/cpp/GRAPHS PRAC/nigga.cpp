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


int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> v(n+4);
        for(ll i=0;i<n;i++) cin >> v[i];
        //for(auto x : v) cout << x << " ";
        //cout << endl;
        ll dups = 0;
       
        ll nga = 1e10 + 10;
        
        sort(v.begin(), v.end());
        unordered_map<ll, ll> cnt;
        for(ll i=0;i<n;i++) {
            cnt[v[i]]+=1;
        }
        ll unq=0;
        vector<ll> bruh;
        for(auto it: cnt){
            //cout  << it.first << " " << it.second << endl;
            if(it.second == 1) unq+=1;
            else bruh.push_back(it.second);
        }
        
        while(k>0){
            if(bruh[bruh.size()-1]>k){
                bruh[bruh.size()-1]-=k;
                unq+=k;
                k=0;
            }
            else{
                unq+=bruh[bruh.size()-1];
                k-=bruh[bruh.size()-1]-1;
                bruh.pop_back();
            }
        }

        ll pairs = 0;
        pairs += unq*(n-1);
        for(int i=0;i<bruh.size();i++){
            pairs += bruh[i] * (n- bruh[i]);
        }
        for(auto x : bruh){
            cout << x << " " ;
        }

        cout << pairs/2 << endl;


        

    }
    return 0;
}