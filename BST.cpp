#include <bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;

	Node (int value){
		data=value;
		left=nullptr;
		right=nullptr;
	}

};

class BST{
	Node* root;

	Node* insertNode(Node* node, int value){
		if (node==nullptr){
			return new Node(value);
		}

		if (value<node->data){
			node->left = insertNode(node->left,value);
		}

		else if (value>node->data){
			node->right = insertNode(node->right, value);
		}
		
		return node;
	}

	Node* deleteNode(Node* node, int value){
		if (node==nullptr){
			return node;
		}

		if (value<node->data){
			node->left=deleteNode(node->left, value);
		}

		else if (value>node->data){
			node->right=deleteNode(node->right, value);
		}

		else{
			if (node->left == nullptr && node->right == nullptr){
				delete node;
				return nullptr;
			}

			else if (node->left == nullptr){
				Node* temp = node->right;
				delete node;
				return temp;
			}

			else if (node->right == nullptr){
				Node* temp = node->left;
				delete node;
				return temp;
			}

			else{
				Node* temp = findMin(node->right);
				node->data = temp->data;
				node->right = deleteNode(node->right, temp->data);
			}
		}
		return node;
	}

	Node* findMin(Node* node){
		while (node && node->left!=nullptr){
			node = node->left;
		}
		return node;
	}

public:

	BST(){
		root=nullptr;
	}


	void insertNode(int value){
		root = insertNode(root, value);
	}

	void deleteNode(int value){
		root = deleteNode(root, value);
	}

	void inorder(){
		inorder(root);
		cout << endl;
	}

private:

	void inorder(Node* node){
		if (node == nullptr) return;

		inorder(node->left);
		cout<<node->data<<" ";
		inorder(node->right);
	}

};

int main(){
	BST tree;

    // Insertion
    tree.insertNode(50);
    tree.insertNode(30);
    tree.insertNode(70);
    tree.insertNode(20);
    tree.insertNode(40);
    tree.insertNode(60);
    tree.insertNode(80);

    cout << "Inorder traversal after insertion: ";
    tree.inorder();
    cout<<"\n";

    // Deletion
    tree.deleteNode(20);
    cout << "Inorder traversal after deleting 20: ";
    tree.inorder();
    cout<<"\n";

    tree.deleteNode(30);
    cout << "Inorder traversal after deleting 30: ";
    tree.inorder();
    cout<<"\n";

    tree.deleteNode(50);
    cout << "Inorder traversal after deleting 50: ";
    tree.inorder();
    cout<<"\n";

    return 0;
}      

















