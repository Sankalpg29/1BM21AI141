#include <iostream>
#include <vector>

class MergeSort {
public:
  int operations;  // Counter for basic operations

  MergeSort() : operations(0) {}

  void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i) {
      L[i] = arr[left + i];
      operations++;
    }

    for (int j = 0; j < n2; ++j) {
      R[j] = arr[mid + 1 + j];
      operations++;
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
      if (L[i] <= R[j]) {
        arr[k++] = L[i++];
      } else {
        arr[k++] = R[j++];
      }
      operations++;
    }

    while (i < n1) {
      arr[k++] = L[i++];
      operations++;
    }

    while (j < n2) {
      arr[k++] = R[j++];
      operations++;
    }
  }

  void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
      int mid = left + (right - left) / 2;
      mergeSort(arr, left, mid);
      mergeSort(arr, mid + 1, right);
      merge(arr, left, mid, right);
    }
  }

  void sort(std::vector<int>& arr) {
    operations = 0;
    mergeSort(arr, 0, arr.size() - 1);
  }
};

int main() {
  std::vector<int> arr = {9, 7, 2, 4, 1, 5};
  MergeSort sorter;
  sorter.sort(arr);

  std::cout << "Sorted array: ";
  for (int num : arr) {
    std::cout << num << " ";
  }
  std::cout << std::endl;

  std::cout << "Basic operations executed: " << sorter.operations << std::endl;

  return 0;
}
