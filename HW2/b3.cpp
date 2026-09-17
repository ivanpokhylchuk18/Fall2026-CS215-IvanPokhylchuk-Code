/*B3 (7 pts, pointer notation only). Read 8 ints into an array, then, WITHOUT using square
brackets anywhere after the declaration ( *(arr + i) or a walking pointer only, in the reading loop
too), print the values in reverse order and report how many are even. The point of the exercise is
Chapter 9's claim that arr[i] is *(arr + i) in disguise; your code demonstrates i*/

//Ivan Pokhylchuk. 0474730
//B3

#include <iostream> // include the iostream library for input and output
using namespace std; // use the standard namespace to avoid prefixing std:: before standard library names

void isEven(int *arr, int size, int *evenCount){ //function to count the number of even integers in an array, takes a pointer to an int array, its size, and a pointer to an int for evenCount as parameters
    *evenCount = 0; //initialize evenCount to 0
    for(int i = 0; i < size; i++){ //loop through the array and check if each number is even
        if(*(arr + i) % 2 == 0){ //if the current number is even, increment evenCount
            (*evenCount)++; // change the value of evenCount by dereferencing the pointer and incrementing it
        }
    }
}

int main(){ //main function
    const int SIZE = 8; //const size of an array of integers
    int arr[SIZE]; //array of integers of size SIZE
    int even = 0; //integer to store the number of even integers in the array
    int *ptr = &even; //pointer to even, so that we can pass it to the isEven function and change its value

    for(int i=0;i<SIZE;i++){ //loop through the array and ask the user to input each integer}
        cout<<"Please enter a number: "<<endl; //ask the user to input a number
        cin>>*(arr+i); //store the input in the current index of the array using pointer notation
    }

    cout << "Values in reverse order: "; //print the values in reverse order using pointer notation
    for(int i = SIZE - 1; i >= 0; i--){ //loop through the array in reverse order and print each value using pointer notation
        cout << *(arr + i) << " "; //print the current value in the array using pointer notation
    }
    cout << endl; //print a new line after printing the values in reverse order

    isEven(arr, SIZE, ptr); //call isEven function with the array and pointer to evenCount

    cout << "Number of even values: " << *ptr << endl; //print the number of even integers in the array by dereferencing the pointer to evenCount

    return 0; //return 0 on successful completion of the program
}