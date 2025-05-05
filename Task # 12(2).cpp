#include <iostream>
using namespace std;


class AVLNode {
	public:
		int data;
		AVLNode* left;
		AVLNode* right;
		int height;
		
	AVLNode(int val){
		data = val;
		left = right = nullptr;
		height = 1;
		
	}
		
};


class AVL {
	public: 
		AVLNode* root;
		
		AVL(){
			root = nullptr;
		}
		
		int getHeight(AVLNode* node){
			return node ? node->height : 0;
		}
		
		int getBalance(AVLNode* node){
			return node ? getHeight(node->left) - getHeight(node->right) : 0;
			
		}
		
		AVLNode* rightRotate(AVLNode* y){
			AVLNode* x = y->left;
			AVLNode* T2 = x->right;
			
			x->right = y;
			y->left = T2;
			
			y->height = 1 + max(getHeight(y->left), getHeight(y->right));
			x->height = 1 + max(getHeight(x->left), getHeight(x->right));
			
			return x;
		}


AVLNode* leftRotate(AVLNode* x){
	AVLNode* y = x->right;
	AVLNode* T2 = y->left;
	
	y->left = x;
	x->right = T2;
	
	x->height = 1 + max(getHeight(x->left), getHeight(x->right));
	y->height = 1 + max(getHeight(y->left), getHeight(y->right));
	
	return y;
	
}
AVLNode* insert(AVLNode* node, int val){
	if (node == nullptr)
		return new AVLNode(val);
		
	if(val < node->data)
		node->left = insert(node->left, val);
	else if (val > node->data)
		node->right = insert(node->right, val);
	else 
		return node;
		
		node->height = 1 + max(getHeight(node->left), getHeight(node->right));
		
		int balance = getBalance(node);
		
		if(balance > 1 && val < node->left->data)
			return rightRotate(node);
			
		if(balance > -1 && val < node->right->data)
			return leftRotate(node);
			
			
		if(balance > 1 && val > node->left->data){
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}
		
		if(balance < -1 && val < node->right->data){
			node->right = rightRotate(node->right);
			return leftRotate(node);
			
		}
		
		return node;
}

	void inorder (AVLNode* node){
		if (node == nullptr) return;
		inorder (node->left);
		cout << node->data << " ";
		inorder(node->right);
	}

};

int main (){
	
	cout <<  "\n AVL TREE " << endl;
	AVL avl;
	avl.root = avl.insert(avl.root, 50);
	avl.root = avl.insert(avl.root, 30);
	avl.root = avl.insert(avl.root, 70);
	avl.root = avl.insert(avl.root, 20);
	avl.root = avl.insert(avl.root, 40);
	avl.root = avl.insert(avl.root, 60);
	avl.root = avl.insert(avl.root, 80);
	cout << " Inorder Traversal (Avl): ";
	avl.inorder(avl.root);
	cout << endl;
	
	return 0;
}


