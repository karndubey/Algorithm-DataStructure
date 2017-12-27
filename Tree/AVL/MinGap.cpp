#include<bits/stdc++.h>
using namespace std;
struct node {
	int key;
	int height;
	int min;
	int max;
	int mingap=INT_MAX;
	struct node *left,*right;
};
class AVL{
	struct node *root;
	public:
		AVL(){
			root=NULL;
		}
		struct node *insertNode(struct node *root,int key);
		struct node *deleteNode(struct node *root,int key);
		struct node *leftRotate(struct node *z);
		struct node *rightRotate(struct node *z);
		int height(struct node *root);
		int getBalance(struct node *root);
		int getkey(struct node *root){
			if(root) return root->key;
			return INT_MAX;
		}
		int getmingap(struct node *root){
			if(root) return root->mingap;
			return INT_MAX;
		}
		struct node *successor(struct node *root);
		void preorder(struct node *root){
			if(root!=NULL){
				cout<<root->key<<" "<<root->min<<" "<<root->max<<" "<<root->mingap<<endl;
				preorder(root->left);
				preorder(root->right);
			}
			
		}
		struct node *getroot();
};
struct node * AVL::insertNode(struct node *root,int key){
	if(root==NULL){
		struct node *temp = new node;
		temp->key=key;
		temp->left=temp->right=NULL;
		temp->height=1;
		temp->min=key;
		temp->max=key;
		temp->mingap=INT_MAX;
		root=temp;
		return root;
	}
	else if(key>root->key){
		root->right=insertNode(root->right,key);
	}
	else if(key <root->key){
		root->left=insertNode(root->left,key);
	}
	else{
		return root;
	}
	root->height=1+std::max(height(root->left),height(root->right));
	if(root->left){
		root->min=root->left->min;
	}
	else{
		root->min=root->key;
	}
	if(root->right){
		root->max=root->right->max;
	}
	else{
		root->max=root->max;
	}
	root->mingap=std::min(min(getmingap(root->left),getmingap(root->right)),
	std::min(abs(root->key-getkey(root->left)),abs(getkey(root->right)-root->key)));
	int balance=getBalance(root);
	if(balance >1 && root->left->key >key){
		return rightRotate(root);
	}
	//Right Right Case
	if(balance <-1 && root->right->key <key){
		return leftRotate(root);
	}
	//Left Right CASE
	if(balance >1 && root->left->key < key){
		root->left=leftRotate(root->left);
		return rightRotate(root);
	}
	//Right Left Case
	if(balance <-1 && root->right->key >key){
		root->right=rightRotate(root->right);
		return leftRotate(root);
	}
	return root;
}
struct node *AVL :: deleteNode(struct node *root,int key){
	// STEP 1: PERFORM STANDARD BST DELETE

	if (root == NULL)
		return root;

	// If the key to be deleted is smaller than the
	// root's key, then it lies in left subtree
	if ( key < root->key )
		root->left = deleteNode(root->left, key);

	// If the key to be deleted is greater than the
	// root's key, then it lies in right subtree
	else if( key > root->key )
		root->right = deleteNode(root->right, key);

	// if key is same as root's key, then This is
	// the node to be deleted
	else
	{
		// node with only one child or no child
		if( (root->left == NULL) || (root->right == NULL) )
		{
			struct node *temp = root->left ? root->left :root->right;

			// No child case
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else // One child case
			*root = *temp; // Copy the contents of
							// the non-empty child
			free(temp);
		}
		else
		{
			// node with two children: Get the inorder
			// successor (smallest in the right subtree)
			struct node* temp = successor(root->right);

			// Copy the inorder successor's data to this node
			root->key = temp->key;

			// Delete the inorder successor
			root->right = deleteNode(root->right, temp->key);
		}
	}

	// If the tree had only one node then return
	if (root == NULL)
	return root;

	// STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
	root->height = 1 + max(height(root->left),
						height(root->right));
	cout<<root->key<<endl;					
	if(root->left!=NULL){
		root->min=root->left->min;
	}
	else{
		root->min=root->key;
	}
	if(root->right!=NULL){
		root->max=root->right->max;
	}
	else{
		root->max=root->key;
	}
	//cout<<getmingap(root->left)<<" "<<getmingap(root->right)<<" "<<abs(root->key-getkey(root->left))<<" "<<abs(getkey(root->right)-root->key)<<endl;
	root->mingap=std::min(std::min(getmingap(root->left),getmingap(root->right)),
	std::min(std::abs(root->key-getkey(root->left)),std::abs(getkey(root->right)-root->key)));
	// STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
	// check whether this node became unbalanced)
	int balance = getBalance(root);

	// If this node becomes unbalanced, then there are 4 cases

	// Left Left Case
	if (balance > 1 && getBalance(root->left) >= 0)
		return rightRotate(root);

	// Left Right Case
	if (balance > 1 && getBalance(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// Right Right Case
	if (balance < -1 && getBalance(root->right) <= 0)
		return leftRotate(root);

	// Right Left Case
	if (balance < -1 && getBalance(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;

}
struct node * AVL :: successor(struct node *root){
	struct node *current=root;
	while(current->left!=NULL){
		current=current->left;
	}
//	cout<<current->key<<endl;
	return current;
}

struct node * AVL::rightRotate(struct node *z){
	struct node *y=z->left;
	struct node *T3=y->right;
	y->right=z;
	z->left=T3;
	z->height=max(height(z->left),height(z->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	if(T3){
		z->min=T3->min;
	}
	else{
		z->min=z->key;
	}
	y->max=z->max;
	z->mingap=std::min(std::min(getmingap(z->left),getmingap(z->right)),
	std::min(std::abs(z->key-getkey(z->left)),std::abs(getkey(z->right)-z->key)));
	y->mingap=std::min(std::min(getmingap(y->left),getmingap(y->right)),
	std::min(std::abs(y->key-getkey(y->left)),std::abs(getkey(y->right)-y->key)));
	return y;
}
struct node * AVL::leftRotate(struct node *z){
	struct node *y=z->right;
	struct node *T3=y->left;
	y->left=z;
	z->right=T3;
	z->height=max(height(z->left),height(z->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	if(T3){
		z->max=T3->max;
	}
	else{
		z->max=z->key;
	}
	y->min=z->min;
	z->mingap=std::min(std::min(getmingap(z->left),getmingap(z->right)),
	std::min(std::abs(z->key-getkey(z->left)),std::abs(getkey(z->right)-z->key)));
	y->mingap=std::min(std::min(getmingap(y->left),getmingap(y->right)),
	std::min(std::abs(y->key-getkey(y->left)),std::abs(getkey(y->right)-y->key)));
	return y;
}
int AVL :: height(struct node *root){
	if(root==NULL)return 0;
	return root->height;
}
int AVL:: getBalance(struct node *root){
	if(root==NULL) return 0;
	return height(root->left)-height(root->right);
}
int main(){
	AVL tree;
	struct node *root=NULL;
	root=tree.insertNode(root,12);
	root=tree.insertNode(root,10);
	root=tree.insertNode(root,20);
	root=tree.insertNode(root,17);
	root=tree.insertNode(root,15);
	cout<<"min "<<root->min<<" max "<<root->max<<" mingap "<<root->mingap<<endl;
	root=tree.insertNode(root,4);
	cout<<"min "<<root->min<<" max "<<root->max<<" mingap "<<root->mingap<<endl;
	root=tree.deleteNode(root,20);
	root=tree.deleteNode(root,30);
	cout<<"min "<<root->min<<" max "<<root->max<<" mingap "<<root->mingap<<endl;
	root=tree.insertNode(root,6);
	root=tree.insertNode(root,11);
	tree.preorder(root);
//	cout<<tree.mingap(5,21,root);
}
