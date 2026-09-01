//Ivan Pokhylchuk, 0474730
//B5


#include <iostream> //include the iostream library for input and output
#include <string> //include the string library to use the string class
using namespace std; //use the standard namespace to avoid prefixing std:: before cout and cin

int main() { //main function
    string line; //creat a string variable to store the user input

    cout << "Enter a line of text: "; //ask the user to enter a line of text
    getline(cin, line); //use getline to read the entire line of text, including spaces, and store it in the line variable

    char vowels[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}; //create an array of vowels to check for them in user's input

    int characterCount = line.length(); //use the length() function to get the number of characters in the line and store it in the characterCount variable
    int wordCount = 0; //create a variable to count the number of words in the line and initialize it to 0
    int vowelCount = 0; //create a variable to count the number of vowels in the line and initialize it to 0
    bool inWord = false; //create a boolean variable to keep track of whether we are currently in a word or not, and initialize it to false

    for (char letter : line) { //a nasted for loop to go through every character in the line and check if it is a vowel or a space, and update the counts accordingly
        for (char vowel : vowels) {
            if (letter == vowel) {
                vowelCount++;
                break;
            }
        }
        if (letter == ' ') {
            inWord = false;
        }
        else if (!inWord) {
            wordCount++;
            inWord = true;
        }
    }

    //print the results
    cout << "Characters: " << characterCount << endl;
    cout << "Words: " << wordCount << endl;
    cout << "Vowels: " << vowelCount << endl;

    return 0; //return 0 to indicate that the program has ended successfully
}