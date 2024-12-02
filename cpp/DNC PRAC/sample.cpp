int partition(vector<pair<double, double>>& arr, int left, int right, int pivotIndex) {
    double pivotValue = arr[pivotIndex].second;
    swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (arr[i].second < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }
    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

// Quickselect algorithm to find the k-th smallest element
double quickselect(vector<pair<double, double>>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left].second;
    }
    int pivotIndex = left + rand() % (right - left + 1);
    pivotIndex = partition(arr, left, right, pivotIndex);
    if (k == pivotIndex) {
        return arr[k].second;
    } else if (k < pivotIndex) {
        return quickselect(arr, left, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, right, k);
    }
}

// Function to find the median of the array
double findMedian(vector<double>& arr) {
    int n = arr.size();
    vector<pair<double, double>> arrWithIndices(n);
    for (int i = 0; i < n; i++) {
        arrWithIndices[i] = {arr[i], arr[i]};
    }
    return quickselect(arrWithIndices, 0, n - 1, n / 2);
}

// Function to find the k closest elements to the median
vector<double> findKClosestToMedian(vector<double>& arr, int k) {
    int n = arr.size();
    double median = findMedian(arr);
    vector<pair<double, double>> distances(n);
    for (int i = 0; i < n; i++) {
        distances[i] = {arr[i], fabs(arr[i] - median)};
    }
    quickselect(distances, 0, n - 1, k - 1);
    vector<double> result(k);
    for (int i = 0; i < k; i++) {
        result[i] = distances[i].first;
    }
    return result;
}

int main() {
    vector<double> S = {1.0, 3.0, 5.0, 7.0, 9.0, 11.0, 13.0};
    int k = 3;
    vector<double> result = findKClosestToMedian(S, k);
    // Output the result
    return 0;
}

vector<int> v(n);
for(int i=)