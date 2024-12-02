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

int median(vector<int> v) {
    vector<int> medians, buf;
    for (int i = 0; i < v.size(); i += 5) {
        sort(v.begin()+i, v.begin() + min(i+5, (int)v.size()));
        int subarray_size = min(5, (int)v.size() - i);
        buf.push_back(v[i + (subarray_size-1)/2]);
    }
    if (buf.size() == 1) return buf[0];
    return median(buf);
}

int partition(vector<int>& v, int low, int high, int pivot) {
    int pivot_ind;
    for (int i = low; i <= high; ++i) {
        if (v[i] == pivot) {
            pivot_ind = i;
            break;
        }
    }
    swap(v[pivot_ind], v[high]);
    int i = low;
    for (int j = low; j < high; ++j) {
        if (v[j] < pivot) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[i], v[high]);
    return i;
}

int kthsmallest(vector<int>& v, int k, int low, int high) {
    if (low == high) return v[low];

    int pivot = median(vector<int>(v.begin() + low, v.begin()+high+ 1));
    int pivot_ind = partition(v, low, high, pivot);

    int rank = pivot_ind-low + 1;
    if (rank == k) return v[pivot_ind];
    else if (k < rank) return kthsmallest(v, k, low, pivot_ind - 1);
    else return kthsmallest(v, k-rank, pivot_ind+1, high);
}

int main() {
    fast;
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cout << kthsmallest(v, k, 0, n-1) << endl;

    // sort(v.begin(), v.end());
    // for(int i=0;i<n;i++)cout << v[i] << " ";
    // nl;
    return 0;
}