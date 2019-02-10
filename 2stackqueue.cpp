#include"llstack.cpp"

class Qby2st{
	public:
	Node* front;
	Node* end;
	stack s1;
	stack s2;

Qby2st(){
	end=s1.top;
}


//Enqueue
void enqueue(int value){
	// push
	s1.push(value);
}

//dequeue
void dequeue(){
	//If queue is empty
	if(s1.top==NULL){cout << "Stop.\n";
	return;	
	}

	else{
		//Transfer the data to stack 2
		while(s1.top!=NULL){
			s2.push(s1.top->data);
			s1.pop();
		}
		//pop 1 element from s2 and transfer everything back
		s2.pop();
		while(s2.top!=NULL){
			s1.push(s2.top->data);
			s2.pop();
		}
	}
}
void size(){
	s1.size();
}

bool isEmpty(){
	s1.isEmpty();
}
//Top 
void top(){
	//Use s1 stack top
	s1.topDisplay();
}
//display
void display(){
	s1.display();
}

};
int main(){
	Qby2st q1;
	
	for(int i=0;i<5;i++){q1.enqueue(i);}
	q1.display();
	for(int i=0;i<3;i++){
		q1.dequeue();
		q1.display();
	}
	q1.size();
return 0;
}
