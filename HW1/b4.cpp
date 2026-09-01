// ...existing code...
#include <iostream>
#include <iomanip>
using namespace std;

// Linear search: count one comparison each time an element is examined.
int linearSearch(const int arr[], int size, int value, int &count) {
    count = 0;
    for (int i = 0; i < size; ++i) {
        ++count;  // one comparison against arr[i]
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

// Binary search: count one comparison each time a probe is checked.
int binarySearch(const int arr[], int size, int value, int &count) {
    count = 0;
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        ++count;  // one probe of arr[mid]
        int mid = left + (right - left) / 2;

        if (arr[mid] == value) {
            return mid;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    const int SIZE = 20;
    int data[SIZE] = {3, 7, 11, 16, 21, 24, 30, 35, 41, 44,
                      50, 55, 61, 67, 72, 78, 83, 88, 94, 99};

    int targets[3] = {3, 55, 99};

    for (int target : targets) {
        int linearCount = 0;
        int binaryCount = 0;

        linearSearch(data, SIZE, target, linearCount);
        binarySearch(data, SIZE, target, binaryCount);

        cout << "Target: " << target << endl;
        cout << "Linear search comparisons: " << linearCount << endl;
        cout << "Binary search comparisons: " << binaryCount << endl;
        cout << endl;
    }

    // The counts show a clear pattern: linear search grows with the target's position in the array, while binary search stays close to logarithmic because it discards half the data each step. Linear search is still reasonable for very small arrays, unsorted data, or one-off searches where sorting or maintaining order is not worth the extra setup.
    return 0;
}