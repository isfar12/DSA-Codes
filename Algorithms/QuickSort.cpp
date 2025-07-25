#include <iostream>
using namespace std;


void quickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int pivot = arr[high]; // Pick the last element as pivot
    int i = low; // Place for swapping

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }

    swap(arr[i], arr[high]); // Place pivot in correct position

    // Recursively sort left and right parts
    quickSort(arr, low, i - 1);
    quickSort(arr, i + 1, high);
}

// Main function
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}