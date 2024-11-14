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
  
class DoublyLinkedList{
public:
	Node* head;

	DoublyLinkedList(){
		head=nullptr;
	}

	Node* insert_beg(int value){
		Node* newNode=new Node(value);

		if (head==nullptr){
			head=newNode;
		}

		else{
			newNode->next=head;
			head->prev=newNode;
			head=newNode;
		}

	    cout<<value<<" inserted at beginning"<<endl;
	    return head;
	}

	Node* insert_end(int value){
		Node* newNode=new Node(value);
		Node* temp= head;

		if (head==nullptr){
			head=newNode;
		}

		else{
			while (temp->next!=nullptr){
				temp=temp->next;
				}	
			temp->next=newNode;
			newNode->prev=temp;
		}
		cout<<value<<" inserted at end"<<endl;
		return head;
	}

	Node* delete_beg(){

		if (head==nullptr){
			cout<< "List is empty, nothing to delete"<<endl;
			return nullptr;
		}

		else{
			Node* temp=head;
			int deleteddata=temp->data;
			head=head->next;
			head->prev=nullptr;
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

		else{
			Node* temp=head;
			while(temp->next!=nullptr){
				temp=temp->next;
			}
			temp->prev->next=nullptr;
			int deleteddata=temp->data;
			delete temp;
			cout<<deleteddata<<" deleted from end"<<endl;
			return head;

		}
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
		Node* temp= head;
		bool flag=false;

		while(temp->next!=nullptr){
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

	Node* find_pns(int value){
		Node* temp=head;

		while(temp != nullptr && temp->data!=value){
			temp=temp->next;
		}

		if (temp==nullptr){
			cout<<"Node not found"<<endl;
		}

		if (temp->prev!=nullptr){
			int pred=temp->prev->data;
			cout<<"Predecessor: "<<pred<<endl;
		}
		else{
			cout<<"No Predecessor(This is the first Node) "<<endl;
		}

		if (temp->next!=nullptr){
			int succ=temp->next->data;
			cout<<"Successor: "<<succ<<endl;
		}
		else{
			cout<<"No Successor(This is the last Node) "<<endl;
		}	
		
		return head;
	}

	void display(){
		if (head==nullptr){
			cout<<"List is empty, nothing to display"<<endl;
		}
		else{Node* temp=head;
			while(temp!=nullptr){
				cout<<temp->data<<"<->";
				temp=temp->next;
			}
		cout<<"nullptr"<<endl;
		}
	}
};



int main(){
	DoublyLinkedList L;
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

















