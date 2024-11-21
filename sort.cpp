#include <iostream>
#include <vector>
using namespace std;

void quickSort(vector<int>& arr, int low, int high);
int partition(vector<int>& arr, int low, int high);

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);  // Sort elements before pivot
        quickSort(arr, pivotIndex + 1, high); // Sort elements after pivot
    }
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++;
            swap(arr[i], arr[j]); // Swap it with the element at i
        }
   
