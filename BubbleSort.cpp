#include <iostream>
using namespace std;

class BubbleSort {
private:
    int* arr;
    int size;
    int operationCount;

public:
    BubbleSort(int* array, int n) {
        arr = array;
        size = n;
        operationCount = 0;
    }

    void sort() {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                    operationCount += 3; // Increment operation count for each comparison and swap
                }
                operationCount += 2; // Increment operation count for each comparison
            }
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getOperationCount() {
        return operationCount;
    }
};

int main() {
    int arr[] = { 64, 34, 25, 12, 22, 11, 90 };
    int size = sizeof(arr) / sizeof(arr[0]);

    BubbleSort bs(arr, size);
    bs.sort();

    cout << "Sorted array: ";
    bs.display();

    cout << "Number of basic operations executed: " << bs.getOperationCount() << endl;

    return 0;
}
