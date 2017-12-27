#include<bits/stdc++.h>
using namespace std;

struct node{
	int key;
	struct node *left,*right,*parent;
	bool color=false;
};

class red_black{
	struct node *root=NULL;
	public:
		struct node *insertNode(struct node *root,int key);
		struct node *rightRotate(struct node *root);
		struct node *leftRotate(struct node *root);
		struct node *newNode(int key);
		bool redChild(struct node *root){
			if(!root->left->color || !root->right->color){
				return false;
			}
			return true;
		}
		bool uncle(struct node *root){
			if(!root)return true;
			return root->color;
		};
		struct node * otherChild(struct node *root){
			if(!root->parent) return root;
			if(root->parent->left==root) return root->parent->right;
			return root->parent->left;
		}
		bool parent(struct node *root);
		void preorder(struct node *root){
			if(root){
				cout<<root->key<<" "<<root->color<<endl;
				preorder(root->left);
				preorder(root->right);
			}
		}
};
struct node * red_black::insertNode(struct node *root,int key){
	
	if(!root){
		struct node *temp= newNode(key);
		temp->color=false;
		return temp;
	}
	if(root->key > key){
		root->left=insertNode(root->left,key);
		root->left->parent=root;
	}
	else if(root->key < key){
		root->right=insertNode(root->right,key);
		root->right->parent=root;
	}
	else{
		return root;
	}
	if(!root->color && !uncle(otherChild(root)) && !redChild(root)){
		root->color=true;
		struct node *temp=otherChild(root);
		temp->color=true;
	}
	if(!root->color && uncle(otherChild(root)) && zigzig(root)){
		
	}
	return root;
}
bool red_black:: zigzig(struct node * root){
	if(!root->left->color && root->parent->left==root) return true;
	if(!root->right->color && root->parent->right==root) return true;
	return false;
}
struct node * red_black:: newNode(int key){
	struct node *temp= new node;
	temp->key=key;
	temp->left=temp->right=temp->parent=NULL;
}
int main(){
	red_black rb;
	struct node * root=NULL;
	root=rb.insertNode(root,10);
	root->color=true;
	root=rb.insertNode(root,5);
	root=rb.insertNode(root,20);
	root=rb.insertNode(root,4);
	rb.preorder(root);
}
