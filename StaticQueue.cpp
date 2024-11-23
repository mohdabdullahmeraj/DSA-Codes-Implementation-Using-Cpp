#include <bits/stdc++.h>
using namespace std;

class Queue{
	int* arr;
	int front;
	int rear;
	int size;

public:
	Queue(int n){
		arr= new int[n];
		front=-1;
		rear=-1;
		size=n;
	}

	bool isFull(){
		return (rear== size-1);
	}

	bool isEmpty(){
		return (front==-1 || front>rear);
	}

	void enqueue(int value){
		if (isFull()){
			cout<<"Queue is full. Cannot enqueue " << value << endl;
		}

		else{
			if (front==-1)
				front=0;
			rear++;
			arr[rear]=value;
			cout << "Enqueued: " << value << endl;
		}
	}

	void dequeue(){
		if (isEmpty()){
			cout << "Queue is empty. Cannot dequeue." << endl;
		}

		else{
			cout << "Dequeued: " << arr[front] << endl;
			front++;
		}
	}

	void peek(){
		if (isEmpty()) {
            cout << "Queue is empty. No front element." << endl;
		}

		else{
			cout<<"Front element is: "<<arr[front]<<endl;
		}

	}

	void display(){
		if (isEmpty()) {
            cout << "Queue is empty." << endl;
		}

		else{
			cout << "Queue elements are: ";
			for (int i=front; i<=rear; i++){
				cout << arr[i] << " ";
			}
			cout<<endl;
		}
	}

};

int main(){
	int n;
	cout<<"Enter size: "<<endl;
	cin>>n;

	Queue Q(n);

	Q.display();
	Q.enqueue(10);
	Q.display();
	Q.enqueue(20);
	Q.display();
	Q.enqueue(30);
	Q.display();
	Q.enqueue(40);
	Q.display();
	
	Q.dequeue();
	Q.display();

	Q.peek();

	return 0;
}      

















