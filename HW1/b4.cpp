//Ivan Pokhylchuk, 0474730
//b4


#include <iostream> // for input/output
using namespace std; //use the standard namespace to avoid prefixing std:: before cout and cin

int linearSearch(const int arr[], int size, int value, int &count) { //linear search function that takes an array, its size, a value to search for, and a reference to a count variable
    count = 0; // set our count to 0
    for (int i = 0; i < size; ++i) { // a for loop to go through every number in the array and check if it is equal to the value we are looking for
        count++; //count +1 if we have to check the next number in the array
        if (arr[i] == value) { //if the number is equal to the value we are looking for, return the index of that number in the array
            return i; //return i
        }
    }
    return -1; //if we have gone through the whole array and did not find the value, return -1
}

int binarySearch(const int arr[], int size, int value, int &count) { //binary search function that takes an array, its size, a value to search for, and a reference to a count variable 
    count = 0; //set our count to 0
    int left = 0; //set the left index to 0
    int right = size - 1; //set the right index to the last index of the array

    while (left <= right) { //while the left index is less than or equal to the right one, we are going to keep searching for the value in the array
        count++;  // count +1 if we have to check the next number in the array
        int mid = left + (right - left) / 2; //middle of the array 

        if (arr[mid] == value) { //if the middle number is equal to the value we are looking for, return the index of that number in the array
            return mid;
        } else if (arr[mid] < value) { //if the middle number is less than the value we are looking for, we are going to search in the right half of the array
            left = mid + 1; //left index is now the middle index + 1
        } else {
            right = mid - 1; //if the middle number is greater than the value we are looking for, we are going to search in the left half of the array
        }
    }
    return -1;
}

int main() {
    const int SIZE = 20; //size of the array
    int data[SIZE] = {3, 7, 11, 16, 21, 24, 30, 35, 41, 44,
                      50, 55, 61, 67, 72, 78, 83, 88, 94, 99}; //array of integers to search through

    int targets[3] = {3, 55, 99}; //array of tergets to search for in the array above 

    for (int target : targets) { //for loop to go through the targets array and search for each target in the data array using both linear and binary search, give us the count of comparisons for each search, and print the results
        int linearCount = 0;
        int binaryCount = 0;

        linearSearch(data, SIZE, target, linearCount);
        binarySearch(data, SIZE, target, binaryCount);

        cout << "Target: " << target << endl;
        cout << "Linear search comparisons: " << linearCount << endl;
        cout << "Binary search comparisons: " << binaryCount << endl;
        cout << endl;
    }

    return 0; //return 0 to indicate that the program has ended successfully
}