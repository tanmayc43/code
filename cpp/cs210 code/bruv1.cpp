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

bool comp(const pair<int,int> &p1, const pair<int,int> &p2) {
    return p1.first < p2.first;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].first;
            cin >> v[i].second;
        }
        sort(v.begin(),v.end(),comp);
        // for(int i=0;i<n;i++) cout << v[i].first << " " << v[i].second << endl;

        priority_queue<int, vector<int>, greater<int>>pq; 
        pq.push(v[0].second);
        for(int i=1;i<n;i++){
            if(v[i].first>=pq.top()){
                pq.pop();
                pq.push(v[i].second);
            }
            else pq.push(v[i].second);
        }
        cout << pq.size() << endl;
    }
    return 0;
}

bool comp(const pair<int,int> &p1, const pair<int,int> &p2) {
    return p1.second < p2.second;
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            cin >> v[i].first;
            cin >> v[i].second;
        }
        sort(v.begin(),v.end(),comp);
        // for(int i=0;i<n;i++) cout << v[i].first << " " << v[i].second << endl;

        int currft=v[0].second, cnt=1;
        for(int i=1;i<n;i++){
            if(v[i].first>=currft){
                cnt+=1;
                currft=v[i].second;
            }
        }
        
        cout << cnt << endl;

    }
    return 0;
}


sort(v.begin(), v.end(), std::greater<int>());
sort(v.rbegin(), v.rend());


bool comp(pair<int, int> p1, pair<int, int> p2) {
    return p1.second/p1.first > p2.second/p2.first;
}
int n,w;
        cin >> n >>w;
        vector<pair<int,int>> v(n);
        for (auto &p : v) cin >> p.first >> p.second;
        sort(v.begin(),v.end(), comp);

        