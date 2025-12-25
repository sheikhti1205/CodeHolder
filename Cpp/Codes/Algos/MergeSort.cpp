#include <iostream>
#include <vector>
#include <algorithm> // Required for std::copy

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    // Create temporary vectors
    std::vector<int> leftArray(subArrayOne);
    std::vector<int> rightArray(subArrayTwo);

    // Copy data to temp vectors leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = arr[mid + 1 + j];

    int indexOfSubArrayOne = 0; // Initial index of first sub-array
    int indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into arr[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        } else {
            arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (indexOfSubArrayOne < subArrayOne) {
        arr[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (indexOfSubArrayTwo < subArrayTwo) {
        arr[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

// Main function that implements Merge Sort
// arr is the vector to be sorted, left is the starting index, and right is the ending index
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right)
        return; // Returns recursively

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

// Function to print a vector
void printVector(const std::vector<int>& arr) {
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    std::cout << "Given vector is \n";
    printVector(arr);

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted vector is \n";
    printVector(arr);

    std::vector<int> arr2 = {38, 27, 43, 3, 9, 82, 10};
    std::cout << "\nGiven vector 2 is \n";
    printVector(arr2);

    mergeSort(arr2, 0, arr2.size() - 1);

    std::cout << "Sorted vector 2 is \n";
    printVector(arr2);

    return 0;
}