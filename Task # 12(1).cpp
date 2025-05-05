#include <iostream>
using namespace std;


class BSTNode {
	public:
		int data;
		BSTNode* left;
		BSTNode* right;
		
		BSTNode(int val){
			data = val;
			left = right = nullptr;
		}
};

class BST{
	public:
		BSTNode* root;
		
		BST(){
			root = nullptr;
		}
		
		BSTNode* insert(BSTNode* node, int val){
			if(node == nullptr)
				return new BSTNode(val);
				
			if(val < node->data)
				node->left = insert(node->left, val);
				
			else if(val > node->data)
				node->right = insert(node->right, val);
				
			return node;
		}
		
		void inorder(BSTNode* node) {
			if (node == nullptr) return;
			inorder(node->left);
			cout << node->data << " ";
			inorder(node->right);
		}
};


int main(){
	cout << " Binary Search Tree: " << endl;
	BST bst;
	bst.root = bst.insert(bst.root, 50);
	bst.insert(bst.root, 30);
	bst.insert(bst.root, 70);
	bst.insert(bst.root, 20);
	bst.insert(bst.root, 40);
	bst.insert(bst.root, 60);
	bst.insert(bst.root, 80);
	cout << " Inorder Traversal (BST): ";
	bst.inorder(bst.root);
	cout << endl;
	
	
	return 0;
}

