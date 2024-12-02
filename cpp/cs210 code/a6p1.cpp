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


int alternating_subsquence(int arr[], int n){
    int up[n]={1};
    int down[n]={1};
    //memset(up,1,sizeof(up));
    //memset(up,1)
 
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]>arr[j]) up[i] = max(up[i],down[j]+1);
            else down[i] = max(down[i],up[j]+1); 
        }
    }
    int max_down=0,max_up=0;
 
    for(int i=0;i<n;i++) max_down = max(max_down,down[i]);
    for(int i=0;i<n;i++) max_up = max(max_up,up[i]);

    return max(max_up,max_down);
}
 
int main(){
    fast;
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout<< alternating_subsquence(arr,n) << endl;
    return 0;
}

