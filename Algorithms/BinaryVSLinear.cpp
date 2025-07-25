#include <bits/stdc++.h>
using namespace std;

int binarySearch(const vector<int>& arr, int target) {
    int iterations = 0;
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            cout << "Element found at index: " << mid << endl;
            iterations++;
            return iterations;
        } else if (arr[mid] < target) {
            iterations++;
            left = mid + 1;
        } else {
            iterations++;
            right = mid - 1;
        }
    }
    cout << "Element not found." << endl;
    return iterations;
}

int linearSearch(const vector<int>& arr, int target) {
    int iterations = 0;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            cout << "Element found at index: " << i << endl;
            iterations++;
            return iterations;
        }
        iterations++;
    }
    cout << "Element not found." << endl;
    return iterations;
}
int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 9;
    int binaryIterations = binarySearch(arr, target);
    cout << "Binary Search Iterations: " << binaryIterations << endl;

    int linearIterations = linearSearch(arr, target);
    cout << "Linear Search Iterations: " << linearIterations << endl;

    return 0;

}