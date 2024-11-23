#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

class Stack{
	Node* top;

public:
	Stack(){
		top=nullptr;
	}

	Node* push(int value){
		Node* newNode=new Node();

		if (!newNode){
			cout<<"Heap Overflow"<<endl;
			return nullptr;
		}

		newNode->data=value;
		newNode->next=top;
		top=newNode;
		cout<<"Pushed: "<<value<<endl;
		return top;
	}

	Node* pop(){
		Node* temp=top;

		if(top==nullptr){
			cout<<"Underflow"<<endl;
			return nullptr;
		}

		cout<<"Popped:"<<temp->data<<endl;
		top=top->next;
		delete temp;
		return top;
	}

	void peek(){
		if (top==nullptr){
			cout<<"Stack is empty"<<endl;
			return;
		}

		cout<<"Top element is: "<<top->data;
	}

	void display(){
		if (top==nullptr){
			cout<<"Stack is empty"<<endl;
		}
		else{
			Node* temp=top;
			cout<<"Stack elements are: "<<endl;
			while(temp!=nullptr){
				cout<<temp->data<<"->";
				temp=temp->next;
			}
			cout<<"nullptr"<<endl;
		}
	}

	~Stack(){
		while(top!=nullptr){
			Node* temp=top;
			top=top->next;
			delete temp;
		}
	}
};


int main(){
	Stack S;  

    S.display();  

    S.push(10);
    S.push(20);
    S.push(30);
    S.display();  

    S.pop();
    S.display();  

    S.peek();    

    return 0;
}      

















