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


int len_odd_palindrome(int arr[],int n, int x){
    int len = 1;
    int i = 0;
    int j = 0;
    while(x-i>0 && x+j<n-1){
        if(arr[x-i]==arr[x+j])len+=2;
        i++;
        j++;
    }
    return len;
}

int len_even_palindrome(int arr[],int n,int x){
    if(arr[x]!=arr[x+1]) return 1;
    int len = 2,i = 1,j = 2;
    while(x-i>0 && x+j<n-1){
        if(arr[x-i]==arr[x+j])len+=2;
        i++;
        j++;
    }
    return len;
}

int max_len_palindrome(int arr[],int n){
    int len =1;
    for(int i=1;i<n-1;i++){
        int odd = len_odd_palindrome(arr,n,i), even = len_even_palindrome(arr,n,i);
        len = max(len,max(odd,even));
    }
    return len;
}

int main(){
    fast;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    cout << max_len_palindrome(arr,n)<< endl;
}