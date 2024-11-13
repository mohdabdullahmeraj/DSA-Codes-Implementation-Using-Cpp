#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* next;

	Node(int value){
		data=value;
		next=nullptr;
	}
};

class SinglyLinkedList{
public:
	Node* head;

	SinglyLinkedList(){
		head=nullptr;	
	}

	Node* insert_beg(int data){
		Node* newNode= new Node(data);
		newNode->next=head;
		head=newNode;
		
		cout<<data<<" inserted at beginning"<<endl;
		return head;
	}

	Node* insert_end(int data){
		Node* newNode=new Node(data);

		if (head==nullptr){
			head=newNode;
			return head;
		}

		Node* temp= head;
		while(temp->next!=nullptr){
			temp=temp->next;
		}
		temp->next=newNode;
		

		cout<<data<<" inserted at end"<<endl;
		return head;
	}

	Node* delete_begin(){

		if (head==nullptr){
			cout<< "List is empty, nothing to delete"<<endl;
			return nullptr;
		}

		Node* temp=head;
		head=head->next;
		delete temp;
		cout<<temp->data<<" deleted from beginning"<<endl;
		return head;
	}

	Node* delete_end(){

		if (head==nullptr){
			cout<< "List is empty, nothing to delete"<<endl;
			return nullptr;
		}

		if (head->next==nullptr){
			delete head;
			head=nullptr;
			cout<<head->data<<" deleted"<<endl;
			return head;
		}

		Node* temp=head;
		while(temp->next->next!=nullptr){
			temp=temp->next;
		}	
		int deletedata=temp->next->data;
		delete temp->next;
		temp->next=nullptr;
		cout<<deletedata<<" deleted from end"<<endl;
		return head;
 	}

 	void search(int value){
 		Node* temp=head;
 		bool flag=false;

		while(temp!=nullptr){
			if (temp->data==value){
				flag=true;
				break;
			}
		temp=temp->next;
		}

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

		while(temp!=nullptr){
			if (temp->data==old_val){
				temp->data=new_val;
				flag=true;
				break;
			}
			temp=temp->next;
		}

		if (flag==true){
			cout<<old_val<<" replaced by "<<new_val<<endl;
		}

		else{
			cout<<old_val<<" does not exist in the list, cannot be replaced"<<endl;	
		}

		return head;
	}

	Node* find_pnd(int value){
		Node* current=head;
		Node* prev=nullptr;

		while(current !=nullptr && current->data!=value){
			prev=current;
			current=current->next;
		}

		if (current==nullptr){
			cout<<"Node not found"<<endl;
		}

		int pred=prev->data;
		int succ=current->next->data;

		cout<<"Predecessor: "<<pred<<endl;
		cout<<"Successor: "<<succ<<endl;
		
		return head;
	}

	Node* display(){
		if (head==nullptr){
			cout<< "List is empty, nothing to display"<<endl;
			return nullptr;
		}

		Node* temp=head;
		while(temp !=nullptr){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"nullptr"<<endl;
		return head;
	}


};
        
int main(){
	SinglyLinkedList L;
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
	L.find_pnd(20);
	
}       

















