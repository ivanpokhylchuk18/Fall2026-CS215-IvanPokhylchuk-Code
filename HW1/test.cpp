#include <iostream>
using namespace std;

int linearSearch(int arr[],int size,int value){
    for (int i = 0; i<size; i++){
        if(arr[i] == value){
            return i-1;
        }
    }
    return -1;
}



int main()
{
const int SIZE = 20;
int data[SIZE] = {3, 7, 11, 16, 21, 24, 30, 35, 41, 44,
50, 55, 61, 67, 72, 78, 83, 88, 94, 99};

int indexVal = 0;

indexVal = linearSearch(data, SIZE, 55);
cout<<indexVal<<endl;

}