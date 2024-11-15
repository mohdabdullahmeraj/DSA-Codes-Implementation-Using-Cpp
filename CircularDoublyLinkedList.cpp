#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;
	Node* prev;

	Node(int value){
		data=value;
		next=nullptr;
		prev=nullptr;
	}
};

class CircularDoublyLinkedList{
public:
	Node* head;

	CircularDoublyLinkedList(){
		head=nullptr;
	}

	Node* insert_beg(int value){
		Node* newNode=new Node(value);

		if (head==nullptr){
			head=newNode;
			head->next=head;
			head->prev=head;
			cout<<value<<" data inserted at beginning"<<endl;
		}

		else{
			Node* last=head->prev;

			newNode->next=head;
			newNode->prev=last;

			head->prev=newNode;
			last->next=newNode;

			head=newNode;

			cout<<value<<" data inserted at beginning"<<endl;
		}

		return head;
	}

	Node* insert_end(int value){

		Node* newNode=new Node(value);

		if (head==nullptr){
			insert_beg(value);
		}

		else{
			Node* last=head->prev;

			newNode->next=head;
			newNode->prev=last;

			last->next=newNode;
			head->prev=newNode;

			cout<<value<<" data inserted at beginning"<<endl;

		}

		return head;
	}

	Node* delete_beg(){
		if (head==nullptr){
			cout<< "List is empty, nothing to delete"<<endl;
			return nullptr;
		}

		else if(head->next==head){
			int deleteddata=head->data;
			delete head;
			head=nullptr;
			cout<<deleteddata<<" deleted from beginning"<<endl;
			return head;
		}

		else{
			Node* temp=head;
			Node* last=head->prev;

			int deleteddata=temp->data;

			head=head->next;
			last->next=head;
			head->prev=last;

			delete temp;
			cout<<deleteddata<<" deleted from beginning"<<endl;
			return head;
		}
	}

	Node* delete_end(){
		if (head==nullptr){
			cout<< "List is empty, nothing to delete"<<endl;
			return nullptr;
		}

		else if(head->next==head){
			int deleteddata=head->data;
			delete head;
			head=nullptr;
			cout<<deleteddata<<" deleted from end"<<endl;
			return head;
		}
		
		else{
			Node* last=head->prev;
			Node* secondlast=last->prev;

			Node* temp=last;
			int deleteddata=temp->data;

			secondlast->next=head;
			head->prev=secondlast;

			delete temp;
			cout<<deleteddata<<" deleted from end"<<endl;
			return head;
		}
	}

	void search(int value){
		Node* temp=head;
		bool flag=false;

		do{
			if (temp->data==value){
				flag=true;
			}
			temp=temp->next;
		}while(temp!=head);

		if (flag==true){
			cout<<value<<" found"<<endl;
		}

		else{
			cout<<value<<" not found"<<endl;	
		}
	}

	Node* update(int old_val, int new_val){
		Node* temp=head;
		bool flag=false;

		do{
			if (temp->data==old_val){
				temp->data=new_val;
				flag=true;
				break;
			}
			temp=temp->next;
		}while(temp!=head);

		if (flag==true){
			cout<<old_val<<" replaced by "<<new_val<<endl;
		}

		else{
			cout<<old_val<<" does not exist in the list, cannot be replaced"<<endl;	
		}
		return head;
	}

	Node* find_pns(int value){

		if (head == nullptr) {
			cout << "List is empty" << endl;
			return nullptr;
   		}

   		else{
   			Node* temp=head;

   			do{
   				if (temp->data==value){
   					Node* pred=temp->prev;
   					Node* succ=temp->next;
   					cout<<"Predecessor: "<<pred->data<<endl;
   					cout << "Successor: " << succ->data << endl;
   					return head;
   				}
   				temp=temp->next;

   			}while(temp!=head);

   			cout << "Node not found" << endl;
    		return head;

   		}
	}

	void display(){

		Node* temp=head;

		if (head==nullptr){
			cout<<"List is empty, nothing to display"<<endl;
		}

		else{
			do{
				cout<<temp->data<<"<->";
				temp=temp->next;
			}while(temp!=head);
		cout<<"circle back"<<endl;
		}
	}

};

int main(){
	CircularDoublyLinkedList L;
	L.display();
	cout<<"\nInsersions:\n"<<endl;
	L.insert_beg(10);
	L.display();
	L.insert_end(20);
	L.insert_end(30);
	L.insert_end(40);
	L.insert_end(50);
	L.insert_end(60);
	L.insert_end(70);
	L.display();
	cout<<"\nDeletion:\n"<<endl;
	L.delete_end();
	L.display();
	cout<<"\nSearch:\n"<<endl;
	L.search(10);
	L.search(11);
	cout<<"\nUpdate:\n"<<endl;
	L.update(10,15);
	L.display();
	L.update(10,12);
	L.display();
	cout<<"\nPredecessor and Successor:\n"<<endl;
	L.find_pns(15);
	L.find_pns(30);
	L.find_pns(60);

}       

















