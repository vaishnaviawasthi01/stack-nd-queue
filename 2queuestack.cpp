#include"llqueue.cpp"

class stby2q{
	public:
	Node* top;
	queue q1;
	queue q2;
	//Construct
	stby2q(){
		top=q1.end;
	}
//Push
void push(int value){
	//enqueue
	q1.enqueue(value);
}

// pop
void pop(){
	//if stack is empty
	if(q1.end==NULL){
		cout<< " STOP!" << endl;
		return;
	}
	else{
		//Take all the elements to q2(except last element of q1)
		while(q1.end->next!=NULL){
			q2.enqueue(q1.front->data);
			q1.dequeue();
		}
		//Delete last element
		q1.dequeue();
		//Take everything back to q1
		while(q2.end!=NULL){
			q1.enqueue(q2.front->data);
			q2.dequeue();
		}
	}
}

//isempty
bool isEmpty(){
	q1.isEmpty();
}

//size
void size(){
	q1.size();
}

//top
void topdisdp(){
	cout << "The top is " << q1.end->data << endl;
}

//display
void display(){
	q1.display();
}

};
int main(){
	stby2q s1;
	
	for(int i=0;i<5;i++){s1.push(i);}
	
	s1.display();
	for (int i=0;i<3;i++){s1.pop();
	s1.display();}
	s1.size();
return 0;
}
