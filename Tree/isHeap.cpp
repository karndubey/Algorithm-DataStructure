#include<bits/stdc++.h>
using namespace std;
struct node{
	int key;
	struct node *left,*right;
};
class binarytree{
	//struct node *root=NULL;
	public:
		struct node * addleft(struct node *root,int key);
		struct node * addright(struct node *root,int key);
		struct node * newNode(int key){
			struct node *temp= new node;
			temp->key=key;
			temp->left=temp->right=NULL;
			return temp;
		}
		bool isHeap(struct node *root);
		bool isComplete(struct node *root,int index,int count);
		int count(struct node *root);
		void preorder(struct node *root){
			if(root){
				cout<<root->key<<" ";
				preorder(root->left);
				preorder(root->right);
			}
		}
};
struct node * binarytree:: addleft(struct node *root,int key){
	if(root==NULL)return newNode(key);
	root->left= addleft(root->left,key);
	return root;
}
struct node * binarytree:: addright(struct node *root,int key){
	if(root==NULL)return newNode(key);
	root->right= addright(root->right,key);
	return root;
}
int binarytree::count(struct node *root){
	if(!root) return 0;
	return 1+count(root->left)+count(root->right);
} 
bool binarytree::isComplete(struct node *root,int index,int count){
	if(root==NULL) return true;
		if(index>=count) return false;
		return isComplete(root->left,2*index+1,count)&& isComplete(root->right,2*index+2,count);
}
bool binarytree :: isHeap(struct node *root){
	if(root->left==NULL || root->right==NULL ){
		struct node *temp=root->left ? root->left : root->right;
		if(!temp) return true;
		if(root->key >= temp->key){
			return true;
		}
		return false;
	}
		else{
			if(root->right->key <= root->key && root->left->key <= root->key){
				return isHeap(root->left) && isHeap(root->right);
			}
			else return false;
		}
	}
int main(){
	struct node *root=NULL;
	binarytree t;
   root = t.newNode(10);
    root->left = t.newNode(9);
    root->right = t.newNode(8);
    root->left->left = t.newNode(7);
    root->left->right = t.newNode(6);
    root->right->left = t.newNode(5);
    root->right->right = t.newNode(4);
    root->left->left->left = t.newNode(1);
    root->left->left->right = t.newNode(2);
    root->left->right->left = t.newNode(1);
 	t.preorder(root);
	int count=t.count(root);
	if(t.isComplete(root,0,count) && t.isHeap(root)) cout<<"yes"<<endl;
	else cout<<"No"<<endl;
}
