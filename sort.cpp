#include <iostream>
#include <vector>

void quickSort(std::vector<int>& arr, int low, int high);
int partition(std::vector<int>& arr, int low, int high);

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);  // Sort elements before pivot
        quickSort(arr, pivotIndex + 1, high); // Sort elements after pivot
    }
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++;
            std::swap(arr[i], arr[j]); // Swap it with the element at i
        }
    }
    std::swap(arr[i + 1], arr[high]); // Place pivot in the correct position
    return i + 1; // Return the pivot index
}
