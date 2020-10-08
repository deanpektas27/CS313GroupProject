//author: Benjamin Thall
#include <iostream>
#include <cstdlib>
#include <bits/stdc++.h>
#include <string>
using namespace std;

void bubSort2d(int *A, int r, int c);
void selSort2d(int *A, int r, int c);
void insSort2d(int *A, int r, int c);

int main(){
	int row, col;
	string sort_choice;	
	
	cout << "Enter number of rows: ";
	cin >> row;
	cout << "Enter number of columns: ";
	cin >> col;
	int arr[row][col];

	//Inputting numbers into the 2d array (matrix)
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cin >> arr[i][j];
		}
	}
	
	//Space to separate the input from the unsorted matrix
	cout << endl << "Here is your unsorted matrix:" << endl;
		
	//Outputting numbers that are saved in the unsorted matrix
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	//Space to separate the unsorted matrix from the sorted matrix\
		and ask user for sorting method
	cout << endl << "What sort would you like to do- bubble, selection, or insertion? (Case sensitive!)" << endl;
	cin >> sort_choice;

	if((sort_choice != "bubble") && (sort_choice != "selection") && (sort_choice != "insertion")){
		cout << "Incorrect choice! Goodbye.";
		return 0;
	}
	
	cout << endl << "Here is your sorted matrix:" << endl;
	//bubble sort the matrix
	if(sort_choice == "bubble") bubSort2d((int*)arr, row, col);
	
	//selection sort the matrix
	if(sort_choice == "selection") selSort2d((int*)arr, row, col);
	
	//insertion sort the matrix
	if(sort_choice == "insertion") insSort2d((int*)arr, row, col);	
	
	//Prints the sorted matrix
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

//Bubble sort function for 2d matrix, ascending order
void bubSort2d(int *A, int r, int c){
	//total # of entries (rows * columns) represented as one integer
	int size = r * c;
	//this is how the parameter *A will be accessed
	int (*a)[c] = (int (*)[c]) A;
	//this first loop ensures the matrix is compared through the end,\
	    the same number of times as its size
	for(int n = 0; n < size; n++){
		//this second loop goes through each row
		for(int i = 0; i < r; i++){
			//this third loop goes through each column
			for(int j = 0; j < c; j++){
				//base case, where there is only one column,\
					there is no need for another for loop
				if((c == 1) && ((i + 1) < r)){
					//if the current singular-row entry value is greater than the next,\
					    then swap them
					if(a[i][0] > a[i+1][0])
						std::swap(a[i][0], a[i+1][0]);				
				}
				//this fourth loop goes through each column as well,\
				    in order to compare within a row\
				    and from the end of a row to the start of the next row
				for(int k = 0; k < c - 1; k++){	
					//if there's at least one other entry in row to compare to, then do it
					if((j + 1) < c){
						//if the current (in the row) is greater than the next, then swap them
						if(a[i][j] > a[i][j+1])
							std::swap(a[i][j], a[i][j+1]);
					}
					//if we've come to the end of the row and there is at least one other row,\
					    then compare with the next value
					else if((j == (c - 1)) && ((i + 1) < r)){
						//if the last value of this row is greater than the first of the next,\
						    the, swap them
						if(a[i][j] > a[i + 1][0])
							std::swap(a[i][j], a[i + 1][0]);
					}
				}
			}
		}
	}
}

//Selection sort function for 2d matrix, ascending order
void selSort2d(int *A, int r, int c){
	//total # of entries (rows * columns) represented as one integer
	int size = r * c;
	//this is how the parameter *A will be accessed
	int (*a)[c] = (int (*)[c]) A;
	//this is the first index in the unsorted subarray
	int start_i;
	//this represents the current minimum value of the idices in the unsorted subarray
	int min_v;
	//this first loop begins with the first index of the unsorted subarray,\
		and the first index is moved to the sorted subarray as the loop is incremented 
	for(int n = 0; n < size - 1; n++){
		start_i = n; //assigns the first index of the unsorted subarray to start_i
		min_v = a[n/r][n%c]; //assigns this the above index's value in the 2d array to min_v
		//these variables will represent the row and column indices of the min_v
		int row_i, col_i;
		//this second loop goes through each row, starting with the current row of start_i
		for(int i = n / r; i < r; i++)
			//this third loop goes through each column
			for(int j = 0; j < c; j++)
				//this ensures that the program doesn't compare with the indices before start_i
				if(((i == n/r) && j >= n%c) || (i > n/r)){
					//compare current index value with the current minimum value
					if(a[i][j] < min_v){ //if it appears that there is a new minimum value
						min_v = a[i][j]; //then label it as such
						row_i = i; //row_i holds row index for the new min_v
						col_i = j; //col_i holds column index for the new min_v
					}
				}
		//swap if necessary
		if(a[start_i/r][start_i%c] != min_v) //if the initial index is not equal to the minimum value
			std::swap(a[start_i/r][start_i%c], a[row_i][col_i]);//then swap starting value with new minimum value
	}
}

//Insertion sort function for 2d matrix, ascending order
void insSort2d(int *A, int r, int c){
	//total # of entries (rows * columns) represented as one integer
	int size = r * c;
	//this is how the parameter *A will be accessed
	int (*a)[c] = (int (*)[c]) A;
	//value is the selected element; k is the index to insert the element in sorted subarray
	int value, k;
	//this is the current minimum value, starting at the first index
	int min_v = a[0][0];
	//this nested loop finds the min_v, a limit for the next nested loop's most inner loop
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			//compare current index value with the current minimum value
			if(a[i][j] < min_v) //if it appears that there is a new minimum value
				min_v = a[i][j]; //then label it as such
		}
	}
	//this first loop goes through the rows
	for(int i = 0; i < r; i++){
		//this second loop goes through every index, starting from the second index
		for(int j = 1; j < size; j++){
			//this selects an element (starting with the second index) to compare
			value = a[i][j];
			//this third loop does the comparison for the shifts 
			for(k = j; (k > 0) && (value >= min_v) && (a[i][k - 1] > value); k--)
				a[i][k] = a[i][k-1]; //shifts greater elements to the right
			a[i][k] = value;//this inserts the selected element at its sorted position
		}
	}
}
