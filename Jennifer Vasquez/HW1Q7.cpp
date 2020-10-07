// Jeniffer Vasquez
// Homework#1.Q7
// The following code will print out "CS313" utilizing
// both Linked Lists and Vectors and time them.

#include <iostream>
#include <vector>
#include<chrono>
using namespace std;
using namespace chrono;
    
    //Linked List for storing "CS313" in Linked List
    struct node {
        char data; //char stored in data
        node* next; //stores the adress of the next node
        
    };
    
    // Function to add info to node on LL
    node* add(char data)
    {
        node* newnode = new node;
        newnode->data = data; //inserts data into node
        newnode->next = NULL; //the next node will be empty
        return newnode;
    }
    
    // Function to insert CS313 to Linked List.
    node* insertString(string word, node* head)
    {
        head = add(word[0]); // sets the first letter of string into head node
        node* curr = head; // curr pointer points to the current node
        
        // insertion takes place here
        for (int i = 1; i < word.size(); i++) {
            curr->next = add(word[i]); // adds the i'th letter into node
            curr = curr->next; // moves curr value to the next node
        }
        return head;
    }
    
    // Function to print the info in all nodes
    void print(node* head)
    {
        node* curr = head;
        while (curr != NULL) { //while you don't find the empty node, print linked list
            cout << "[" << curr->data << "]" << " -> ";
            curr = curr->next;
        }
    }

    //Vector Function
    void printVector(){
    vector<char> v ({'C', 'S', '3', '1', '3'}) ;
    
    for(int i = 0; i < 5 ; ++i)
        cout<< "<" << v[i] << ">" << " ";

    }
    
    //main
    int main()
    {
        //Linked List Main
        string word = "CS313"; //create string CS313
        
        node* head = NULL;
        head = insertString(word, head);
        
        cout << "The Linked List contains the string:\n";
        
        auto start = high_resolution_clock::now(); // Start timing for LL
        print(head);
        auto stop = high_resolution_clock::now(); // End timing for LL
        
        auto duration = duration_cast<microseconds>(stop - start); // Calculate total time for LL
        
        cout << "\nTime taken by Linked List: " << duration.count() << " microseconds" << endl; // Print total time in microseconds
        
        //Vector Main
        cout<< "\nThe vector contains the string:\n";
        
        auto start2 = high_resolution_clock::now(); // Start timing for Vector
        printVector();
        auto stop2 = high_resolution_clock::now(); // End timing for Vector
        
        auto duration2 = duration_cast<microseconds>(stop2 - start2); // Calculate total time for Vector
        
        cout << "\nTime taken by Vector: " << duration2.count() << " microseconds" << endl; // Print total time in microseconds
        
        return 0;
        
    }

    
