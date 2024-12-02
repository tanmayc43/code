#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


int merge_and_count(vector<int>& arr, vector<int>& temp, int left, int mid, int right) {
    int i = left, j = mid + 1;
    int k = left;   // Starting index to be sorted
    int count = 0;  // Count of significant inversions

    while (i <= mid && j <= right) {
        if (arr[i] > 2LL * arr[j]) {
            count += (mid - i + 1); 
            j++;
        } 
        else i++; 
    }

    i = left;
    j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }

    while (i <= mid) temp[k++] = arr[i++];
    while (j <= right) temp[k++] = arr[j++];

    for (i=left; i<=right; i++) arr[i] = temp[i];
    return count;
}



int merge_sort_and_count(vector<int>& arr, vector<int>& temp, int left, int right) {    
    if(right-left<=1){
        return max(arr[left],)
    }
    int count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        count += merge_sort_and_count(arr, temp, left, mid);
        count += merge_sort_and_count(arr, temp, mid + 1, right);

        count += merge_and_count(arr, temp, left, mid, right);
    }
    return count;
}

int count_significant_inversions(vector<int>& arr) {
    int n = arr.size();
    vector<int> temp(n);
    return merge_sort_and_count(arr, temp, 0, n - 1);
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin >> v[i];
    cout << count_significant_inversions(v) << endl;
    return 0;
}







