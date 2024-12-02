#include <iostream>
#include <vector>
using namespace std;

// Function to count the occurrences of a candidate element in the array segment A[low..high]
int countInRange(const vector<int>& A, int low, int high, int candidate) {
    int count = 0;
    for (int i = low; i <= high; ++i) {
        if (A[i] == candidate) {
            count++;
        }
    }
    return count;
}

// Function to find the majority element in the array segment A[low..high]
int majorityElement(const vector<int>& A, int low, int high) {
    // Base case: only one element, return it as the majority element
    if (low == high) {
        return A[low];
    }

    // Divide: find the middle of the array
    int mid = low + (high - low) / 2;

    // Recursively find majority elements in both halves
    int leftMajor = majorityElement(A, low, mid);
    int rightMajor = majorityElement(A, mid + 1, high);

    // If both halves agree, return that as the majority element
    if (leftMajor == rightMajor) {
        return leftMajor;
    }

    // Otherwise, count each candidate in the entire segment
    int leftCount = countInRange(A, low, high, leftMajor);
    int rightCount = countInRange(A, low, high, rightMajor);

    // Return the element with the higher count if it is a majority
    int n = high - low + 1;
    if (leftCount > n / 2) {
        return leftMajor;
    }
    if (rightCount > n / 2) {
        return rightMajor;
    }

    // If neither candidate is a majority, return -1 (indicating no majority element)
    return -1;
}

// Function to find the majority element in the entire array
int findMajorityElement(const vector<int>& A) {
    return majorityElement(A, 0, A.size() - 1);
}

int main() {
    vector<int> A = {1, 2, 1, 1, 1, 2, 3};  // Example array

    int result = findMajorityElement(A);

    if (result != -1) {
        cout << "The majority element is: " << result << endl;
    } else {
        cout << "No majority element exists." << endl;
    }

    return 0;
}
