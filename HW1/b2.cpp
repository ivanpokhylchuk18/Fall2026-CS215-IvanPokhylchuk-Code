//Ivan Pokhylchuk, 0474730
//B2


#include <iostream>//include the iostream library for input and output
using namespace std; //use the standard namespace to avoid prefixing std:: before cout and cin

// Reads and validates a positive number
double getPositiveNumber(string prompt) {
    double value; //create a variable to store the user input

    cout << prompt; //prompt the user for input
    cin >> value; //store the user input in the variable

    while (value <= 0) { //while loop to check if the input is not negative or zero
        cout << "Please enter a positive number: "; //ask for positice number
        cin >> value;
    }

    return value; //return value 
}

// Calculates the total fuel cost
double calculateFuelCost(double miles, double mpg, double pricePerGallon) {
    double gallonsNeeded = miles / mpg; //calculate the number of gallons needed for the trip
    return gallonsNeeded * pricePerGallon; //calculate the total fuel cost by multiplying the number of gallons needed by the price per gallon
}

// Prints the trip report
void printReport(double miles, double mpg, double pricePerGallon, double cost) {
    //print the trip report with the calculated values
    cout << "Trip Fuel Cost Report:" << endl;
    cout << "Miles: " << miles << endl;
    cout << "Miles per gallon: " << mpg << endl;
    cout << "Price per gallon: $" << pricePerGallon << endl;
    cout << "Estimated fuel cost: $" << cost << endl;
}

int main() { //main function
    //declare variables for miles, miles per gallon, price per gallon, and fuel cost
    double miles;
    double mpg;
    double pricePerGallon;
    double fuelCost;


    //get user input for miles, miles per gallon, and price per gallon using the getPositiveNumber function
    miles = getPositiveNumber("Enter the number of miles: ");
    mpg = getPositiveNumber("Enter the vehicle's miles per gallon: ");
    pricePerGallon = getPositiveNumber("Enter the price per gallon: ");
    //calculate the fuel cost using the calculateFuelCost function
    fuelCost = calculateFuelCost(miles, mpg, pricePerGallon);
    //print the trip report using the printReport function
    printReport(miles, mpg, pricePerGallon, fuelCost);

    return 0; //return 0 to indicate that the program has ended successfully
}