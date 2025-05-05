#include < iostream>
using namespace std;

class TreeNode {
	public:
		int data;
		TreeNode* left;
		TreeNode* right;
		
		TreeNode(int value) {
			data = value;
			left = right = NULL;
		}
};

void DFS_Tree(TreeNode root){
	if (root == NULL) return;
	
	cout << root->data << " ";
	DFS_Tree(root->left);
	DFS_Tree(root->right);
	
}

int main (){
	TreeNode*  root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	
	cout << " DFS in Tree: " ;
	DFS_Tree(root);
	cout << endl;
	return 0;
	
}
