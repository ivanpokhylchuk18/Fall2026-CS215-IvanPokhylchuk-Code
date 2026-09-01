//Ivan Pokhylchuk, 0474730
//B1
//Temperature Readings

#include <iostream> //include the iostream library for input and output
using namespace std; //use the standard namespace to avoid prefixing std:: before cout and cin

int main() { //main fucntion

    double count = 0; //variable for counting the number of readings
    double sum = 0; //variable for summing the readings
    double lowest = 0; //variable for storing the lowest reading
    double highest = 0; //variable for storing the highest reading

    while (true) { //while loop to ask the user to enter the reading until they enter -999 to stop
        double temp; //variable for storing the current reading
        cout << "Enter a temperature reading (or -999 to stop): "; //ask the user to enter a reading
        cin >> temp; //store the reading in the temp variable
        if (temp == -999) { //break the while loop if the user enters -999
            break;
        }
        else { //if the user enters a valid reading, check if it is the lowest or highest reading and update the sum and count
            if (count == 1) {  //if this is the first reading, set both lowest and highest to the current reading
                lowest = temp;
                highest = temp;
            }
            else {
                if (temp < lowest) {
                    lowest = temp;
                }
                if (temp > highest) {
                    highest = temp;
                }
            }
            sum += temp;
            count++;
        }
    }
    if (count == 0) { //if the user did not enter any readings, print a message saying that no readings were enterd
        cout << "No readings were entered." << endl;
    }
    else {
        double average = sum / count; //after the while loop break, calculate the avg reading and output the results of all the readings entered by the user

        cout << "Count: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << average << endl;
        cout << "Lowest: " << lowest << endl;
        cout << "Highest: " << highest << endl;
    }
    return 0; //return 0 to indicate that the program has ended successfully
}