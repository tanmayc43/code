#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int maxprod(vector<int>&a, int l, int h){
    if(h-l<=1)return max(a[l],a[h]);
    int mid = (l+h)/2;
    int lres = maxprod(a, 0,mid );
    int rres = maxprod(a,mid+1,h);

    int lmax_prod=INT_MIN, lcurr_prod=1, lmin_prod=INT_MAX;
    for(int i=mid;i>=0;i--){
        lcurr_prod*=a[i];
        if(lcurr_prod>lmax_prod)lmax_prod=lcurr_prod;
        if(lcurr_prod<lmin_prod)lmin_prod=lcurr_prod;
    }

    int rmax_prod=INT_MIN, rcurr_prod=1, rmin_prod=INT_MAX;
    for(int i=mid+1;i<=h;i++){
        rcurr_prod*=a[i];
        if(rcurr_prod>rmax_prod)rmax_prod=rcurr_prod;
        if(rcurr_prod<rmin_prod)rmin_prod=rcurr_prod;
    }

    return max(max(lres,rres), max(lmax_prod*rmax_prod, lmin_prod*rmin_prod));
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    cout << maxprod(v,0,n-1) <<endl;
    
    return 0;
}


