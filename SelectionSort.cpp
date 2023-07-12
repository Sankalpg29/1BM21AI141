#include <iostream>

class SelectionSort {
private:
    int* arr;
    int size;
    int operations; // Counter for basic operations

public:
    SelectionSort(int* array, int n) {
        arr = array;
        size = n;
        operations = 0;
    }

    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
        operations += 3; // Counting swap as 3 basic operations
    }

    void selectionSort() {
        for (int i = 0; i < size - 1; ++i) {
            int minIndex = i;
            for (int j = i + 1; j < size; ++j) {
                if (arr[j] < arr[minIndex]) {
                    minIndex = j;
                    operations += 1; // Counting comparison as 1 basic operation
                }
                operations += 1; // Counting comparison as 1 basic operation
            }
            swap(arr[i], arr[minIndex]);
        }
    }

    void printArray() {
        for (int i = 0; i < size; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    int getOperationsCount() {
        return operations;
    }
};

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    SelectionSort selectionSort(arr, size);
    selectionSort.selectionSort();

    std::cout << "Sorted array: ";
    selectionSort.printArray();

    std::cout << "Basic operations executed: " << selectionSort.getOperationsCount() << std::endl;

    return 0;
}
