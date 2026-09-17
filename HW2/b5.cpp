/*B5 (7 pts, find the crimes, then fix them). The program below compiles and usually even prints
something. It contains two distinct memory errors.
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
Submit b5.cpp containing: (a) a comment block at the top naming both errors, quoting for each
the line of the original program where it happens; (b) a corrected version of the program using
new / delete correctly; and (c) below it in a comment, 1 to 2 sentences on how a vector<int>
version would make both errors impossible (writing the vector version is optional and welcome).*/

//Ivan Pokhylchuk, 0474730
//B5

//Error 1: Dangling pointer - Line: int *copy = ages; After deleting ages, copy points to deallocated memory.
//Error 2: Memory leak - Line: int *extra = new int[n]; The allocated memory for extra is not deleted before the program ends.


#include <iostream>
using namespace std;

int main() {
    int n = 5;

    int *ages = new int[n];
    
    for (int i = 0; i < n; i++)
        ages[i] = 20 + i;

    int *copy = ages;

    // Corrected version: Deallocate ages before using copy
    delete [] ages;

    cout << copy[2] << endl;

    int *extra = new int[n];

    for (int i = 0; i < n; i++)
        extra[i] = i;

    cout << extra[4] << endl;

    // Corrected version: Deallocate extra before the program ends
    delete [] extra;

    return 0;
}