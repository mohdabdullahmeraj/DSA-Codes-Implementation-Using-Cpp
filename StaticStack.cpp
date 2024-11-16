#include <bits/stdc++.h>
using namespace std;

class Stack{
	int top;
	int *arr;
	int size;

public: 
	Stack(int n){
		top=-1;
		arr =new int[size];
		size=n; 
	}

	void push(int value){
		if (top==size-1){
			cout<<"Overflow"<<endl;
		}

		else{
			top++;
			arr[top]=value;
			cout<<"Pushed: "<<value<<endl;
		}
	}

	void pop(){
		if (top==-1){
			cout<<"Underflow"<<endl;
		}

		else{
			cout<<"Popped: "<<arr[top]<<endl;
			top--;
		}
	}

	void peek(){
		if (top==-1){
			cout<<"Underflow"<<endl;
		}

		else{
			cout<<"Top element is: "<<arr[top]<<endl;
		}
	}

	void display(){
		if (top==-1){
			cout<<"Stack is empty"<<endl;
		}

		else{
			cout<<"Stack elements are:"<<endl;
			for (int i=top; i>=0; i--){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
		}
	}

	~Stack(){
		delete[] arr;
	}
};
int main(){
	int n;
	cout<<"Enter size: "<<endl;
	cin>>n;

	Stack S(n);

	S.display();
	S.push(10);
	S.display();
	S.push(20);
	S.display();
	S.push(30);
	S.display();
	S.push(40);
	S.display();
	
	S.pop();
	S.display();

	S.peek();

	return 0;
}      

















