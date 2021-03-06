#include<iostream>
using namespace std;
//declaring class
//ll

class Node{
	public:
	//Data
	int data;
	//Pointer to next Node
	Node * next;
	//Constructor that makes ptr to NULL
	Node(){
		next = NULL;
	}
	
};

class linkedlist{
	public:
	
	Node * head;
	Node * tail;
	
	//Constructor
	linkedlist(){
		head = NULL;
		tail = NULL;
	}
	
	//insert
	void insert(int value){
		//If 1st node is added
		Node * temp = new Node;
		// Insert value in the node
		temp->data = value;
		// 1st Node only
		if(head==NULL){
			head = temp;
		}
		
		// Any other Node
		else{
			tail->next = temp;
		}
		tail = temp;
		
	}
	
	void insertAt(int pos, int value){
		//Create a node
		Node * temp = new Node;
		//Storing the data
		temp-> data = value;

		//If ll is empty
		if(head==NULL){
			head = temp;
			tail = temp;
		}
		else{
			// Reach the place before the pos
			Node * current = head;
			int i =1;
			while(i < pos-1){
				i++;
				current = current->next;
				if(current == NULL){
					
					cout << "Insert function might help you in this case." << endl;
					return;
				}
			}

			if(pos != 1){
			//moving pointers like magic!
			temp->next = current->next;
			current->next = temp;
				if(current == tail){tail = current->next;}
			}
			// Update the code for 1st pos.
			else{temp->next = head;
			head = temp;}
		}
	}

	//Delete at any position
	void deleteAt(int pos){
		//When there is no element in LL
		if(head==NULL){
			cout << "Please stop.can't perform function" << endl;
			cout << endl;
		}

		//Deleting the first position
		else if(pos == 1){
			Node * temp = head;
			head = head->next;
			temp->next = NULL;
			delete temp;
		}
	
		else{
			// Reach the place before the position
			Node * current = head;
			int i =1;
			while(i<pos-1){
				i++;
				current = current->next;
				}

			// Reach the place at the pos
			Node * temp = head;
			int j =1;
			while(j < pos){
				j++;
				temp = temp->next;
				if(temp==NULL){
					cout << "Can't perform the function.." << endl;
					return;
				}
			}
			
			//Moving pointers like magic!
			current->next = temp->next;
			delete temp;
		}
	}

	//Deletion of last element
	void del(){
		//store tail in temp
		Node * temp = tail;
		
		//When there is no element
		if(head == NULL){
			cout << "Please stop.Can't perform function. " << endl;
			cout << endl;
		}
		//When there is only one element
		if(head == tail){
			head = NULL;
			tail = NULL;
		}
		
			
		else{			
			//Node before tail has to point to NULL
			Node * current = head;
			
			while(current->next != tail){
				current = current->next;
			}
			current->next = NULL;
			//update tail
			tail = current;
		}

			//delete temp
			delete temp;
		
	}

	//Count the number of items in the list
	void countitems(){

		int count = 0;
		Node * curr = head; 
		while(curr != NULL){
			count++;
			curr = curr->next;
			}
		cout << "Number of items = " << count << endl;
	}
	
	//Display
	void display(){
		Node * current = head;
		
		while(current != NULL){
			cout << current->data << "->";
			current = current->next;
		}
		cout << "NULL" << endl;
	}

};

//queue
class queue{
	public:
		Node * front;
		Node * end;
		LinkedList l1;
	
	//Constructor
	queue(){
		end = l1.head;
		front = l1.tail;
	}

	//enter value from end
	void endqueue(int value){
		//Use insertAt from ll
		l1.insertAt(1,value);
		//Update front and end
		end=l1.head;
		front=l1.tail;

	}

	//remove element from Front
	void delqueue(){
		l1.del();
		end=l1.head;
		front=l1.tail;
	}

	// check if queue is empty
	bool isEmpty(){
		if(end == NULL){return true;}
		return false;
	}

	//size of queue
	void size(){
		l1.countItems();
	}

	//display
	void display(){
		l1.display();
	}

	//end display
	void enddisp(){
		cout << "The head element is " <<l1.head->data << endl;
	}

};
int main(){
	queue q1;
	
	for(int i=0;i<5;i++){q1.endqueue(i);}
	q1.display();
	for(int i=0;i<3;i++){
		q1.delqueue();
		q1.display();}
	q1.size();
return 0;
}

