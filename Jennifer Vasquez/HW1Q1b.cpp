// Jeniffer Vasquez
// HW#1Q1(b)
// The purpose of this code is to generate random strings utilizing
// both Vectors and Linked List & time both.

#include <iostream>
#include <time.h>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;


// Linked List for generating random strings
struct Node{
    string letter; // type of data store in letter is string
    Node* next; // stores the address of the next link
};

struct Node* head2; //pointer to the first node

void FirstLet(Node *&first, Node *&last, string letter){
    Node *l = new Node; //creates a new node
    l->letter = letter;   //set the letter of this node;
    l->next = NULL;    //pointer to the next node;
    first = l;
    last = l;
};

bool empty(Node *first) // checks if node is empty
{
    if (first == NULL) // Checks if the first node is empty & will return true if it is, else false
    {
        return true;
    }
    else return false;
    
}
void insert(Node *&first, Node *&last, string letter) // insert info in node
{
    if (empty(first))
    {
        FirstLet(first, last, letter); // will insert the info on the first node
    }
    else {
        Node *l = new Node; // if first element if full, then you move on to the next nodes and change the positions
        l->letter = letter; // set letter value inside node
        l->next = NULL; // next node to equal NULL
        last->next = l;
        last = l;
        
    }
}
void printList(Node *current) // print list
{
    while (current != NULL) // print until find an empty node
    {
        cout << current->letter; // print current letter
        current = current->next; // move to point to nect node
    }
}



// Vector Function for generating random strings
void vectorStr() {
    int r; // initializing r to an integer value
    int len = 5; // the lenghth of string to be 5
    vector<string> v2(5); // initializes string vector of sz 5
    srand(time(NULL));
    
    cout<< "\nVector #2 contains following random strings: \n\n";
    
    for( int i = 0; i < 5 ; ++i){ // outer loop responsible for amount of strings built
        for( int j = 0; j < len; ++j){ // inner loop responsible for length of string
            r = rand() % 26;   // generate a random number and store in r
            v2[i] = 'a' + r; // Convert to a character from a-z and store in i'th place in vector
            
            cout<< v2[i]; // print the value in the i'th place of vector
        }
        cout<< endl;
    }
}

int main() {
    int r;
    string letter;
    
    auto t1 = high_resolution_clock::now(); // begins timing linked list
    
    Node *first = NULL;
    Node *last = NULL;
    
    //LINKED LIST MAIN
    cout<< "\nLinked List #2 contains the following random strings: \n";
    
    for (int i = 0; i < 5 ; ++i){
        r = rand() % 26;
        letter = 'a' + r ;
        insert (first, last, letter);
        printList (first);
        cout<< "\n";
    }
    auto t2 = high_resolution_clock::now(); // stops timing linked lists
    auto duration1 = duration_cast<microseconds>( t2 - t1 ).count(); // calculates duration
    
    cout<< "\nLinked List takes " << duration1 << " microseconds.\n";
    
    //VECTOR MAIN
    auto t3 = high_resolution_clock::now(); //start timing of functions
    vectorStr();
    auto t4 = high_resolution_clock::now(); //start timing of functions
    auto duration = duration_cast<microseconds>( t4 - t3 ).count(); // calculating time taken to complete functions
    
    cout<< "\nVector takes " << duration << " microseconds.\n";
    
    return 0;
}
