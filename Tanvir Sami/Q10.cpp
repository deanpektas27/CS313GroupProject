//Tanvir Sami
#include <iostream>

using namespace std;

//LINKEDLIST
struct Node{
  int data; //the type of data to be stored(integer)
  struct Node* next; //store the address of the next link
};

struct Node* head; //pointer to the first node
void insert(int value){//add value to the nodes;
  Node *n = new Node(); //creating a new node;
    n->data = value;   //set the value of this node; 
    n->next = head;    //pointer to the next node;
    head = n;          //head pointing to the node;
};

void swapNodes(Node *first, Node *second){
	int temp = first->data;
	first->data = second -> data;
	second -> data = temp;
}

void oddFirst(Node *head, int s){
  //int swapCounter = 0;
	Node *first; //will always point to the start  
	Node *last = NULL; //point the last node to null
  
	for (int i=0; i<s; i++){
		first = head;//the loop is on the current node
		while(first->next != last){
			if ((first->data)%2==0 && (first->next->data)%2==1){ //if the first node is an even number and the next node is odd number, then continue
				swapNodes(first, first->next); 
			}
			first = first->next; //move on to the next node
		}
		//as the largest number is at the end of the list
		//check already sorted list
		last = first;
	}
}


void sortOdd(Node *head, int s){
	Node *first; //will always point to the start  
	Node *last = NULL; //last node will point to null
	for (int i=0; i<s; i++){
		first = head; //the loop is on the current node
		while(first->next != last){//while we are not on the last node
    if((first->next->data)%2==1){ //check if next node is odd
			if (first->data > first->next->data){//if the next number is greater
				swapNodes(first, first->next); //swap
			}
    }
			first = first->next;//move onto next node
		}
		last = first;
	}
}

void sortEven(Node *head, int s){
	Node *first; //will always point to the start  
	Node *last = NULL; 
	for (int i=0; i<s; i++){
		first = head;
		while(first->next != last){

    if((first->data)%2==0 && (first->next->data)%2==0){//check if both nodes being swapped is even
			if (first->data > first->next->data){
				swapNodes(first, first->next); 
			}
    }
			first = first->next;
		}
		last = first;
	}
}


void printList(Node *head){
	Node *first = head;
	while(first){ //print nodes untill first points to null
		cout <<"[" <<first->data << "|" << "->" <<"]  ";
		first = first->next; //continue to next node
	}
	cout<<endl<<endl;
}




int main(){
srand((unsigned) time(0));//random numbers based on current time


int k = 10;
  for(int i=k-1; i>=0; i--){
    insert(rand()%100); //random numbers from 0 to99
  }


	cout<<"Linked list before sorting:"<<endl;
	printList(head);

	cout<<"Linked list after odd first:"<<endl;
  oddFirst(head, k);
	printList(head);

cout<<"Linked list after sorting odd:"<<endl;
  sortOdd(head, k);
  printList(head);

  cout<<"Linked list after sorting even:"<<endl;
  sortEven(head, k);
  printList(head);


return 0;
}