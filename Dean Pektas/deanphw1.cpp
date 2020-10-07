#include <iostream>
#include <string>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
//Dean Pektas CS313 Question 5 Group 6
using namespace std;


//Set a counter equal to length that decreases as each entry is looked at
int counter, remaining;


//Swaps two addresses representing numbers in an array
void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;

}

//Prints every entry in a given array up to n length 
void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


//perform unique sort (bubble)
void sorttwo(int arr[], int n, int counter){
    //If we are coming from first sort, only sort the remaining. 
    //If arr is less than 10 originally, start sorting from beginning.
    cout << "Now in second sort Y... " << endl;
    if(counter == 0){
        remaining = 0;
        cout << "Sort will begin at the first value of the array... " << endl; 
    }
    if(counter > 0){ 
        remaining = n-counter-1; 
        cout << "Sort must begin at pos " << remaining << ", aka value " << arr[remaining] << endl;
    }

    //Begin second sort here based on length of arr and/or amount of entries left
    int i, j;
    for(i = 0; i < n-1; i++){
        for(j = remaining; j < n-i-1; j++){
            if(arr[j] > arr[j+1]) swap(&arr[j], &arr[j+1]);
        }
    }

}


void sortone(int arr[], int n){
    //Func to sort arr using selection sort until we have less than
    //10 entries to look at
    cout << "Now in first sort X... " << endl;
    //Set counter to length of arr, decrease during loop
    counter = n;
    cout << "Length of array is: " << counter << endl << endl;
    cout << "Sorting for an arr greater than 10: " << endl;
    //Perform selection sort in loop

    //As we go thru each i pos, check if the next value, j, is less 
    //than that value in i.
    int i, j, min;

    //As boundary of array decreases, compare to each element in arr
    for(i = 0; i < n-1; i++){
        if(counter < 10) break;
        //pos i will begin as smallest arr element
        min = i;
        //for each value above min, if smaller, set min to smaller value
        for(j = i+1; j < n; j++){
            if(arr[j] < arr[min]) min = j;
        }
        swap(&arr[min], &arr[i]);
        cout << "We now have " << counter << " entries to look at" << endl << endl;  
        counter--; 

    }
    cout << "Sorted array until we have less than 10 entries: " << endl;
    printArr(arr,n);
    cout << "We now have less than 10 array entries, performing second sort " << endl;
    sorttwo(arr, n, counter);
}


void decide(int *arr, int n){
    //Func to decide what sort to use on arr based on length
    //sortone will sort array larger than 10
    cout << "Now in deciding func... " << endl;
    if(n > 10) sortone(arr, n);
    //sorttwo will sort array smaller than 10
    else if(n < 10) sorttwo(arr, n, 0);
}


int main(){
    //Example array with a set size
    int a[] = {5,3,1,2,4,17,64,35,72,204,532,115,33,29};
    //For some reason, size must be indicated like below so only the contents of arr are displayed.
    int n = sizeof(a)/sizeof(a[0]); 
    //Print unsorted array first
    cout << "Unsorted array: " << endl ;
    printArr(a, n);
    //decide if length of example array is less than or greater than 10, choose which sort function to go thru
    decide(a, n);
    //print newly sorted array.
    printArr(a, n);

}
