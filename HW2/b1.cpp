//Ivan Pokhylchuk, 0474730
//B1

#include <iostream> //include the iostream library for input and output
using namespace std; //use the standard namespace to avoid prefixing std:: before standard library names

int main(){ //main function
    int numReadings; //integer for the number of readings
    cout << "How many readings do you have? "; //ask the user for the number of readings
    cin >> numReadings; //store the number of readings in the variable numReadings

    if(numReadings == 0){ //if the number of readings is 0, print a message and exit the program
        cout << "No readings to process." << endl;
        return 0;
    }

    double* readings = new double[numReadings]; //create a pointer to a double array of size numReadings, so the user can choose the size of the array before it compiles, therefore allowing for dynamic memory allocation

    for(int i = 0; i < numReadings; i++){ //loop through the number of readings and ask the user to input each reading
        cout << "Enter reading " << (i + 1) << ": ";
        cin >> readings[i];
    }

    double sum = 0; //double for sum of readings
    double highest = readings[0]; //double for highest reading, initialized to the first reading
    for(int i = 0; i < numReadings; i++){ //go through the readings and calculate the sum and highest reading
        sum += readings[i];
        if(readings[i] > highest){
            highest = readings[i];
        }
    }
    double average = sum / numReadings; //get the avg

    cout << "Average: " << average << endl; //output the average and highest reading
    cout << "Highest: " << highest << endl;

    // Release memory
    delete[] readings; // ~!IMPORTANT!~ very important to free the memory allocated for the readings array to avoid memory leaks
    readings = nullptr; // set the array pointer to nullptr to avoid dangling pointer issues

    return 0; //return 0 on successful completion of the program
}