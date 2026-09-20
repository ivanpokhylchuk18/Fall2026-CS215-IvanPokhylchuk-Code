//Ivan Pokhylchuk, 0474730
//B5

//I had to put the wrong program in a comment because it was causing memory errors and I wanted to show the errors that were present in the original code. The corrected version of the program is below the commented-out code.
/*
#include <iostream>
using namespace std;

int main() {

int n = 5;

int *ages = new int[n];

for (int i = 0; i < n; i++)
    ages[i] = 20 + i;

int *copy = ages;

delete [] ages;

cout << copy[2] << endl; 

int *extra = new int[n];

for (int i = 0; i < n; i++)
    extra[i] = i;

cout << extra[4] << endl;

return 0;
}
*/

//All Errors:
//1. Memory error: Accessing deleted memory. Line: cout << copy[2]
//2. Memory error: Memory leak. Line: int *extra = new int[n]; (extra is not deleted before program ends)

//Vector<int> version would make both errors impossible because it automatically manages memory allocation and deallocation, preventing access to deleted memory and eliminating memory leaks.
// That is why using new and delete is not necessary when using vector<int> in C++.
//And it is also more efficient and safer to use vector<int> instead of raw pointers for dynamic arrays in C++.
//And the code looks cleaner and more readable with vector<int> implementation, just a preference to me!

//Corrected version of the program with a vector<int> implementation:
#include <iostream>
using namespace std;
#include <vector>

int main() {
    int n = 5;
    vector<int> ages(n);
    for (int i = 0; i < n; i++)
        ages[i] = 20 + i;

    cout << ages[2] << endl;

    vector<int> extra(n);
    for (int i = 0; i < n; i++)
        extra[i] = i;

    cout << extra[4] << endl;

    return 0;
}