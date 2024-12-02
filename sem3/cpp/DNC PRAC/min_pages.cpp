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


bool ispossible(vector<int>v, int books, int students, int curr_min){
    int students_req = 1, curr_sum=0;
    for(int i=0;i<books;i++){
        if(v[i]>curr_min) return false;
        else if(curr_sum + v[i] > curr_min){
            students_req+=1;
            curr_sum+=v[i];
            if(students_req > students)return false;
        }
        else curr_sum+=v[i];
    }
    return true;
}

int min_pages(vector<int>v, int books, int students){
    if(books<students) return -1;

    long long sum=0;
    int maxm_pages =INT_MIN;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
        maxm_pages=max(v[i], maxm_pages);
    }

    int start = maxm_pages, end=sum, res=INT_MAX;
    while(start<=end){
        int mid = start + (end-start)/2;
        if(ispossible(v, books, students, mid)){
            res = mid;
            end = mid-1;
        }
        else start=mid+1;

    }
    return res;

}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int books, students;
        cin >> books >> students;
        vector<int>pages(books);
        int n=books;
        for(int i=0;i<books;i++)cin>>pages[i];
        cout << min_pages(pages,books,students) << endl;
    }
    return 0;
}