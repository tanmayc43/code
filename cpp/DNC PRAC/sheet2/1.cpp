#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using ll = long long;

void dnc_heapify(vector<int>& v, int ind, int n) {
    int left_child = 2 * ind + 1;
    int right_child = 2 * ind + 2;
    int smallest = ind;

    if (left_child < n && v[left_child] < v[smallest]) {
        smallest = left_child;
    }

    if (right_child < n && v[right_child] < v[smallest]) {
        smallest = right_child;
    }

    if (smallest != ind) {
        swap(v[ind], v[smallest]);
        dnc_heapify(v, smallest, n);  
    }
}

void dnc_buildheap(vector<int>& v, int low, int high) {
    if (low == high) return;  

    int mid = low + (high - low) / 2;

    dnc_buildheap(v, low, mid);
    dnc_buildheap(v, mid + 1, high);

    for (int i = (high - low + 1) / 2 - 1; i >= 0; i--) {
        dnc_heapify(v, i, high - low + 1);  
    }
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];

        dnc_buildheap(v, 0, n - 1);

        for (int i = 0; i < n; i++) cout << v[i] << " ";
        cout << endl;
    }
    return 0;
}
