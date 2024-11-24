#include <bits/stdc++.h>
using namespace std;

class Dequeue{
	int front;
	int rear;
	int size;
	int* dequeue;

public:
	Dequeue(int n){
		front=-1;
		rear=-1;
		size=n;
		dequeue=new int[size];
	}

	~Dequeue() {
        delete[] dequeue;
    }

    bool isFull(){
    	return((front==0 && rear==size-1) || (front==rear+1));
    }

    bool isEmpty(){
    	return(front==-1);
    }

    void enqueueFront(int value){
    	if (isFull()){
    		cout << "Dequeue is Full!" << endl;
            return;
    	}

    	if (isEmpty()){
    		front=rear=0;
    	}

    	else if(front==0){
    		front=size-1;
    	}

    	else{
    		front--;
    	}

    	dequeue[front]=value;
    	cout << "Enqueued " << value << " at Front" << endl;
    }

    void enqueueRear(int value){
    	if (isFull()){
    		cout << "Dequeue is Full!" << endl;
            return;
    	}

    	if (isEmpty()){
    		front=rear=0;
    	}

    	else if(rear==size-1){
    		rear=0;
    	}

    	else{
    		rear++;
    	}

    	dequeue[rear]=value;
    	cout << "Enqueued " << value << " at Rear" << endl;
    }

    void dequeueFront(){
    	if (isEmpty()){
    		cout << "Dequeue is Empty!" << endl;
            return;
    	}

    	cout << "Dequeued " << dequeue[front] << " from Front" << endl;
    	if (front==rear){
    		front=rear=-1;
    	}

    	else if(front==size-1){
    		front=0;
    	}

    	else{
    		front++;
    	}

    }

    void dequeueRear(){
    	if (isEmpty()){
    		cout << "Dequeue is Empty!" << endl;
            return;
    	}

    	cout << "Dequeued " << dequeue[rear] << " from Rear" << endl;
    	if (front==rear){
    		front=rear=-1;
    	}

    	else if (rear==0){
    		rear=size-1;
    	}

    	else{
    		rear--;
    	}

    }

    void displayFrontToRear(){
    	if (isEmpty()) {
            cout << "Dequeue is Empty!" << endl;
            return;
        }

        cout << "Dequeue elements are (Front to Rear): ";
        int i=front;
        while(i!=rear){
        	cout << dequeue[i] << " ";
            i = (i + 1) % size;
        }

        cout<<dequeue[rear]<<endl;
    }

    void displayRearToFront(){
    	if (isEmpty()){
    		cout << "Dequeue is Empty!" << endl;
            return;
    	}

    	cout << "Dequeue elements are (Rear to Front): ";
        int i = rear;
        if (front <= rear) { 
            while (i >= front) {  
                cout << dequeue[i] << " ";
                i--;
            }
        } else {
            while (i >= 0) {  
                cout << dequeue[i] << " ";
                i--;
            }
            i = size - 1;  
            while (i >= front) {
                cout << dequeue[i] << " ";
                i--;
            }
        }
        cout << endl;
    }

};

int main(){
	Dequeue dq(5);  

	dq.displayFrontToRear();
    dq.displayRearToFront();

    dq.enqueueRear(30);
    dq.enqueueRear(40);

    dq.displayFrontToRear();
    dq.displayRearToFront();

    dq.enqueueFront(20);
    dq.enqueueFront(10);
    
    dq.displayFrontToRear();
    dq.displayRearToFront();

    dq.dequeueFront();
    dq.dequeueRear();
    dq.displayFrontToRear();
    dq.displayRearToFront();

    return 0;
}      

















