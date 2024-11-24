#include <bits/stdc++.h>
using namespace std;

class circularQueue{
	int front;
	int rear;
	int size;
	int* queue;

public:
	circularQueue(int n){
		front=-1;
		rear=-1;
		size=n;
		queue =new int[n];
	}

	void enqueue(int value){
		if ((rear+1) % size == front){
			cout<< "Queue is Full"<<endl;
			return;
		}

		if (front==-1){
			rear=front=0;
		}

		else{
			rear=(rear+1) % size;
		}

		queue[rear]=value;
		cout<<value << " enqueued to the queue." << endl;
	}

	void dequeue(){
		if (front==-1){
			cout << "Queue is Empty" << endl;
            return;
		}

		cout << queue[front] << " dequeued from the queue." << endl;

		if (front==rear){
			front=-1;
			rear=-1;
		}

		else{
			front=(front+1) % size;
		}
	}

	void peek(){
		if (front==-1){
			cout << "Queue is Empty" << endl;
            return;
        }

		cout << "Front element is: " << queue[front] << endl;	
	}

	void display(){
		if (front==-1){
			cout << "Queue is Empty" << endl;
            return;
        }

        cout << "Queue elements are: ";
       	int i=front;
       	while(i!=rear){
       		cout << queue[i] << " ";
       		i=(i+1) % size;
       	}

       	cout << queue[rear] << endl;
	}
};

int main(){
	circularQueue Q(5);

	Q.display();

	Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.enqueue(50);

    Q.display();

    Q.dequeue();
    Q.dequeue();

    Q.display();

    Q.peek();

    return 0;
}      

















