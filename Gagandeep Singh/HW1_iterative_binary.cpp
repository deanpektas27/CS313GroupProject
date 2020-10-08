//
//  main.cpp
//  HW1 CS313 iterative Binary Search
//
//  Created by GAGANDEEP SINGH  on 10/7/20.
//  Copyright © 2020 GAGANDEEP SINGH . All rights reserved.
//


#include <stdio.h>
#include <iostream>
using namespace std;
//Gagandeep singh Q2
// C++ program to implement iterative Binary Search


// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
        
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
        
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
    
    // if we reach here, then element was
    // not present
    return -1;
}

int main(void)
{
    int arr[100];
    srand((unsigned)time(NULL));
    // This function makes use of the computer's internal clock to control the choice of the seed(starting value)
    for (int i = 1; i < 10000000; i++)
        
    {
        arr[i] = 1+ rand() % 10;
        // To generate random numbers we use rand() function and '1' is first number in range and 10 is number of terms used in your range
    }
    
    int x = 10;
    // number to search in arrays
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch(arr, 0, n - 1, x);
    //calling binarySearch function
    (result == -1) ? cout << "Element is not present in array"
    : cout << "Element is present at index " << result;
    
    return 0;
}

// This program is iterative binary search, it repeat the while loop untill it find searching item. In recursive program:
//  1. Compare x with the middle element.
//  2.If x matches with middle element, we return the mid index.
//  3.Else If x is greater than the mid element, then x can only lie in     right half subarray after the mid element. So we recur for right      half.
//  4.Else (x is smaller) recur for the left half.
