
#include <iostream>
#include <vector>

class BinarySearch {
private:
    std::vector<int> arr;

public:
    BinarySearch(const std::vector<int>& inputArray) : arr(inputArray) {}

    int search(int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // Return -1 if the target is not found
    }
};

int main() {
    std::vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 6;

    BinarySearch binarySearch(array);
    int index = binarySearch.search(target);

    if (index != -1) {
        std::cout << "Target found at index " << index << std::endl;
    } else {
        std::cout << "Target not found" << std::endl;
    }

    return 0;
}
