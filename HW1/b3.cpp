//Ivan Pokhylchuk, 0474730
//B3

#include <iostream> //include the iostream library for input and output
#include <vector> //include the vector library to use the vector container
using namespace std; //use the standard namespace to avoid prefixing std:: before cout and cin

int main() { //main function
    vector<double> scores; //vector to store the exam results
    double score; //variable for score input

    while (true) { //while loop to keep asking the user to enter a score until he enters a negative number
        cout << "Enter an exam score (negative number to finish): ";
        cin >> score;

        if (score < 0) { //if the user enters a negative number, break the loop
            break;
        }

        scores.push_back(score); //add the score to the vector
    }


    if (scores.size() == 0) { //if the user did not enter any scores, print no scores were entered
        cout << "No scores were entered." << endl;
    } 
    else {
        //if the user entered some scores, then calculate the average and count how many scores are above the averages
        double sum = 0; //var for a sum of scores
        for (double s : scores) { //for loop to go through the vector and add each score to the sum
            sum += s;
        }
        double average = sum / scores.size(); //calculate the average by dividing the sum by the number of scores

        int countAboveAverage = 0; //var for counting how many scores are above the average
        for (double s : scores) { //another for loop to go throug the vector and check if s>average, if it is then increment the countAboveAverage variable
            if (s > average) {
                countAboveAverage++;
            }
        }

        //print the results
        cout << "Number of scores: " << scores.size() << endl;
        cout << "Average score: " << average << endl;
        cout << "Number of scores above average: " << countAboveAverage << endl;

        return 0; //return 0 to indicate that the program has ended successfully
    }

}