//Ivan Pokhylchuk, 0474730
//B1

#include <iostream> //include the iostream library for input and output

int main(){ //main function
    int numReadings; //integer for the number of readings
    std::cout << "How many readings do you have? "; //ask the user for the number of readings
    std::cin >> numReadings; //store the number of readings in the variable numReadings

    if(numReadings == 0){ //if the number of readings is 0, print a message and exit the program
        std::cout << "No readings to process." << std::endl;
        return 0;
    }

    double* readings = new double[numReadings]; //create a pointer to a double array of size numReadings, so the user can choose the size of the array before it compiles, therefore allowing for dynamic memory allocation

    for(int i = 0; i < numReadings; i++){ //loop through the number of readings and ask the user to input each reading
        std::cout << "Enter reading " << (i + 1) << ": ";
        std::cin >> readings[i];
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

    std::cout << "Average: " << average << std::endl; //output the average and highest reading
    std::cout << "Highest: " << highest << std::endl;

    // Release memory
    delete[] readings; // ~!IMPORTANT!~ very important to free the memory allocated for the readings array to avoid memory leaks
    readings = nullptr; // set the array pointer to nullptr to avoid dangling pointer issues

    return 0; //return 0 on successful completion of the program
}