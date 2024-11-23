#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
};

class Queue{
	Node* front;
	Node* rear;

public:
	Queue(){
		front=nullptr;
		rear=nullptr;
	}

	bool isEmpty(){
		return front == nullptr;
	}

	Node* enqueue(int value){
		Node* newNode=new Node();
		newNode->data=value;
		newNode->next=nullptr;

		if (isEmpty()){
			front=rear=newNode;
		}

		else{
			rear->next=newNode;
			rear=newNode;
		}

		cout << "Enqueued: " << value << endl;
        return rear;
	}

	Node* dequeue(){
		if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return nullptr;
        }

        else{
        	Node* temp=front;
        	cout << "Dequeued: " << front->data << endl;
        	front=front->next;
        	if (front == nullptr) { 
                rear = nullptr;
            }
            temp->next = nullptr;

        	delete temp;
        	return nullptr;
        }
	}

	void peek(){
		if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
        }

        else{
        	cout<<"Front element is: "<<front->data<<endl;
        }
	}

	void display(){
		if (isEmpty()) {
            cout << "Queue is empty." << endl;
        }

        else{
        	cout << "Queue elements: ";
        	Node* temp=front;
        	while(temp!=nullptr){
        		cout<<temp->data<<"->";
        		temp=temp->next;
        	}

        	cout<<"nullptr"<<endl;;
        }
	}

	~Queue(){
		while(front!=nullptr){
			Node* temp=front;
			front=front->next;
			delete temp;
		}
	}
};

int main(){
	Queue Q;  

    Q.display();  

    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.display();  

    Q.dequeue();
    Q.display();  

    Q.peek();    

    return 0;
}      

















