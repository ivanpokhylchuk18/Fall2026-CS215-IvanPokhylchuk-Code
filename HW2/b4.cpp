//Ivan Pokhylchuk, 0474730
//B4

#include <iostream> //include the iostream library for input and output operations
using namespace std; //use the standard namespace to avoid prefixing std:: before standard library names

void selectionSort(int *arr, int size, int *comparisonCount) { //function to perform selection sort on an array and count the number of comparisons made
    *comparisonCount = 0; //initialize comparisonCount to 0
    for (int i = 0; i < size - 1; i++) { //loop through the array
        int minIndex = i; //initialize minIndex to the current index
        for (int j = i + 1; j < size; j++) { //loop through the unsorted portion of the array
            (*comparisonCount)++; //increment comparisonCount for each comparison made
            if (arr[j] < arr[minIndex]) { //if the current element is less than the current minimum, update minIndex
                minIndex = j; //update minIndex to the index of the new minimum element
            }
        }
        if (minIndex != i) { //if minIndex has changed, swap the current element with the minimum element found
            //swap with using a temporary variable
            int temp = arr[i]; //store the current element in a temporary variable
            arr[i] = arr[minIndex]; //replace the current element with the minimum element
            arr[minIndex] = temp; //replace the minimum element with the current element stored in temp
        }
    }
}

int main() { //main function
    const int sizes[] = {8, 16, 32}; //array of sizes to test
    cout << "Size\tComparisons\tFormula" << endl; //print table header
    for (int size : sizes) { //loop through the sizes array
        int *arr = new int[size]; //dynamically allocate an array of the current size
        for (int i = 0; i < size; i++) { //fill the array with values (for simplicity, using sequential values)
            arr[i] = i; //fill the array with sequential values from 0 to size-1
        }
        int comparisonCount; //variable to store the number of comparisons made
        selectionSort(arr, size, &comparisonCount); //call selectionSort function with the array and pointer to comparisonCount
        cout << size << "\t" << comparisonCount << "\t\t" << (size * (size - 1)) / 2 << endl; //print the size, comparison count, and formula value
        delete[] arr; //free the dynamically allocated memory
    }
    return 0; //return 0 on successful completion of the program
}

