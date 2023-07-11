#include <iostream>
#include <vector>

// Class to keep track of the basic operations
class OperationCounter {
public:
    static int count;

    static void increment() {
        count++;
    }
};

int OperationCounter::count = 0;

// Swap two elements in the vector
void swap(std::vector<int>& arr, int i, int j) {
    OperationCounter::increment();
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Partition the array and return the pivot index
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr, i, j);
        }
    }

    swap(arr, i + 1, high);
    return i + 1;
}

// Quicksort algorithm
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    std::vector<int> arr = {9, 3, 2, 7, 6, 1, 5, 4, 8};
    int n = arr.size();

    OperationCounter::count = 0;
    quickSort(arr, 0, n - 1);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    std::cout << "Number of basic operations executed: " << OperationCounter::count << std::endl;

    return 0;
}
