//Ivan Pokhylchuk. 0474730
//B2

#include <iostream> //include the iostream library for input and output
using namespace std; //use the standard namespace to avoid prefixing std:: before standard library names

void minMax(const int *arr, int size, int *low, int *high){ //void function of minMax, that take a pointer to an int array, its size, pointers to low and high as paramaters
    *low = arr[0]; //initialize low to the first element of the array
    *high = arr[0]; //initialize high to the first element of the array

    for(int i = 1; i < size; i++){ //loop through the array starting from the second element
        if(arr[i] < *low){ //if the current element is less than low, update low
            *low = arr[i];
        }
        if(arr[i] > *high){ //if the current element is greater than high, update high
            *high = arr[i];
        }
    }
}

void calculateSumAndAvg(const int *arr, int size, int *sum, double *avg){ //my own void function that takes a pointer to an int array, its size, pointers to sum and avg as paramaters
    *sum = 0; //initialize sum to 0
    for(int i = 0; i < size; i++){ //loop through the array and calculate the sum
        *sum += arr[i]; //pointer of sum is dereferenced and the value of the current element is added to it
    }
    *avg = *sum / size; //calculate the average and store it in avg
}


int main(){ //main function
    const int SIZE = 6; //const size of an array of integers
    int arr[SIZE]; //array of integers of size SIZE
    int low, high; //low and high integers to store the lowest and highest values in the array
    int sum; //sum of the integers in the array
    double avg; //avg of the integers in the array

    for (int i = 0; i < SIZE; i++){ //loop through the array and ask the user to input each integer
        cout << "Enter integer " << (i + 1) << ": ";
        cin >> arr[i];
    }

    if (SIZE == 0){ //if the size of the array is 0, print a message and exit the program
        cout << "No integers to process." << endl;
        return 0;
    }

    minMax(arr, SIZE, &low, &high); //call minMax function with the array and pointers to low and high
    cout << "Lowest value: " << low << endl;
    cout << "Highest value: " << high << endl;

    calculateSumAndAvg(arr, SIZE, &sum, &avg); //call calculateSumAndAvg function with the array and pointers to sum and avg
    cout << "Sum: " << sum << endl;
    cout << "Average: " << avg << endl;


    return 0; //return 0 on successful completion of the program

}