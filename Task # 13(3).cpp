#include <iostream>
#include <queue>
using namespace std;

class TreeNode{
	public:
		int data;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int value){
			data = value;
			left = right = NULL;
		}
};

void BFS_Tree(TreeNode* root){
	if (root == NULL) return;
	queue<TreeNode*> q;
	q.push(root);
	
	while(!q.emtpy()){
		TreeNode* current = q.front();
		q.pop();
		cout << current->data << " ";
		
		if(current->left)q.push(current->right);
		if(current->right)q.push(current->right);
		
	}
}

int main(){
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->left->right = new TreeNode(5);
	
	cout << " BFS in Tree: ";
	BFS_Tree(root);
	cout << endl;
	return 0;
	
	
}


