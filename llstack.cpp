#include <iostream>
using namespace std;
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
		if(head==NULL){head = temp;
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
					cout << "This position has not yet been created." << endl;
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

//stack

class stack{
	public:
		Node * top;
		LinkedList l1;
	//Constructor
	stack(){
		top = l1.head;
	}

	//Functions used in questions
	// put element from top
	void push(int value){
		//insertAt(int pos, int value)
		l1.insertAt(1,value);
		// Top = new_head(i.e. changing head)
		top = l1.head;
	}

	//remove element from top
	void pop(){
		//void deleteAt(int pos)
		l1.deleteAt(1);
		//top = new_head)(changing head)
		top = l1.head;
	}

	//check if stack box is empty
	bool isEmpty(){
		if(top == NULL){return true;}
		return false;
	}

	//length of stack
	void size(){
		//Use countItems
		l1.countItems();
	}

	//top display.
	void topDisplay(){
		cout << "The top is " << l1.head->data << endl;
	}

	//display
	void display(){
		l1.display();
	}
};
int main(){
	stack s1;
	
	for(int i=0;i<5;i++)
		{s1.push(i);}
	s1.display();
	for (int i=0;i<3;i++)
	{s1.pop();
	 s1.display();}
	return 0;
}

