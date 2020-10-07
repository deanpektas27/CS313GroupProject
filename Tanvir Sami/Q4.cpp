//Tanvir Sami 
#include <iostream>

using namespace std;


//ARRAY
void sortArray(int array[], int n){ //sort arr[i]
   int i, j;  
   int temp; //temporary value for the swap
   int sortCounter = 0; //counter for how many times a swapp occured
    for (i=0; i<n-1; i++) 
      for (j=0; j<n-i-1; j++){ 
        if (array[j] > array[j+1]){
          temp = array[j]; //store array so the value isn't lost
          array[j] = array[j+1]; //perform swap
          array[j+1] = temp; //returned the stored array
          sortCounter ++; //increase counter
        }
      }
    cout << "Steps taken to sort:" << sortCounter <<endl;
}




//LINKEDLIST
struct Node{
  int data; //the type of data to be stored(type integer)
  struct Node* next; //store the address of the next link
};

struct Node* head; //pointer to the first node
void insert(int value){//add value to the nodes;
  Node *n = new Node(); //creating a new node;
    n->data = value;   //set the value of this node; 
    n->next = head;    //pointer to the next node;
    head = n;          //head pointing to the node;
};





void sortLink(Node *head, int s){
  int swapCounter = 0;
	Node *first; //will always point to the start  
	Node *last = NULL; //point the last node to null
	for (int i=0; i<s; i++){ //for loops runs untill the provided size (int s)
		first = head; //first node will point to the head
		while(first->next != last){ //untill we reach the last node
			if (first->data > first->next->data){ //if the data in this node is larger than the data in the next continue
        int temp = first->data; //store data in temp so we don't lose the data
	      first->data = first->next->data; //perform swap
	      first->next->data = temp; //restore the stored data
        swapCounter++; //increase counter
			}
			first = first->next; //go to next node
		}
		//check already sorted list
		last = first;
	}
  cout << "Steps taken to sort: " << swapCounter << endl;
}



//print functions
void printArray(int array[], int s){  //print array of size s
    int i;  
    for (i=0; i<s; i++)  
        cout<<"Array["<<i+1<<"]:"<<array[i]<<endl;
    cout << endl;  
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

  srand((unsigned) time(0));//random numbers based on time
    
//RANDOM ARRAY
  cout << "Random Array before sorting:" <<endl;

  int s = 10; //number of elements in both array and linked list 

  int Array[s];//innitialize array
   for(int i=0; i<s;i ++)
      Array[i]=rand()%100; //set a random value into the array[i] from 0 to 99
       for(int i=0; i<s; i++)
         cout<<"Array["<<i+1<<"]:"<<Array[i]<<endl;
  cout <<endl;

//copy the same array into linked list for fair comparison
  for(int l=s-1; l>=0; l--){
    insert(Array[l]);//save it into linked list for now before array[] is sorted
  }

//RANDOM ARRAY SORTED
  cout << "Random Array after sorting:" <<endl;
  sortArray(Array, s);//sort using bubble sort
  printArray(Array, s); 
  cout << endl;


//LINKED LIST
	cout<<"Linked list before sorting:"<<endl;
	printList(head);

	cout<<"Linked list after sorting:"<<endl;
  sortLink(head, s);//sort using bubble sort
	printList(head);


return 0;
}
