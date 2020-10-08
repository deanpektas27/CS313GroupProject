// Jeniffer Vasquez
// HW#1Q1(a)
// The following program is designed to time how long it takes to generate
// random integers using Vectors & Linked Lists.

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;

//Linked List for randomizing 10 numbers
struct Node{
    int num; // integer value stored in num
    Node* next; // stores the address of the next link
};

struct Node* head; //pointer to the first node

void FirstEl(Node *&first, Node *&last, int num){
    Node *n = new Node; //creates a new node
    n->num = num;   //set the value of this node
    n->next = NULL;    //pointer to the next node
    first = n;
    last = n;
};

bool isEmpty(Node *first) // checks if node is empty
{
    if (first == NULL) // Checks if the first node is empty & will return true if it is, else false
    {
        return true;
    }
    else return false;
    
}
void insert(Node *&first, Node *&last, int num)// insert info in node
{
    if (isEmpty(first))
    {
        FirstEl(first, last, num); // will insert the info on the first node
    }
    else {
        Node *n = new Node; // if first element if full, then you move on to the next nodes and change the positions
        n->num = num; // set num value inside node
        n->next = NULL; // next node to equal NULL
        last->next = n;
        last = n;
        
    }
}
void printList1(Node *current) // print list
{
    cout << "Linked List #1 contains the following 10 random #s: \n\n";
    
    while (current != NULL) // while the current value is not NULL, print value inside node
    {
        cout << "[" << current->num << "]" << "->";
        current = current->next; // change & advance the value of current to the next node
    }
    cout << endl;
}



//Vector Function for randomizing 10 integers
void vector1() {
    vector<int> v(10); // initializes integer vector of  sz 10
    
    generate(v.begin(), v.end(), [](){ // function will generate random # from 0-100 and store it inside vector from beginning to end
        return rand() % 100 + 1;
    });
    
    cout << "\nVector #1 contains following 10 random #'s: \n\n";
    
    for (auto it = v.begin(); it != v.end(); ++it) // print the contents of vector v from beginning to end
        cout << "<" <<  *it << ">" << " ";
}



//Main
int main(){
    
    //Linked List
    int number;
    
    auto t1 = high_resolution_clock::now(); // begins timing linked list
    
    Node *first = NULL;
    Node *last = NULL;
    
    //PRINTING INTEGER LINKED LIST
    srand(time(NULL));
    
    for (int i = 0; i < 10; i++)
    {
        number = (rand() % 100 + 1);
        insert(first, last, number);
        
    }
    printList1(first);
    
    auto t2 = high_resolution_clock::now(); // stops timing linked lists
    auto duration1 = duration_cast<microseconds>( t2 - t1 ).count(); // calculates duration
    
    cout<< "\nLinked List takes " << duration1 << " microseconds.\n";
    
    //VECTOR CALL & PRINT
    auto t3 = high_resolution_clock::now(); //start timing of functions
    vector1();
    auto t4 = high_resolution_clock::now(); // end timing of functions
    auto duration2 = duration_cast<microseconds>( t4 - t3 ).count(); // calculating time taken to complete functions
    
    cout<< "\n\nVector takes " << duration2 << " microseconds.\n";
    
}
