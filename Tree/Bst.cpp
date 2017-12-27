#include<bits/stdc++.h>
using namespace std;
struct node{
	int key;
	struct node *left,*right,*parent;
};
class bst{
	struct node *root;
	public:
	bst(int v);
	void addnode(int v);
	void deletenode(int v);
	void inorder(struct node *temp);
	void dfs();	
	struct node* root1();
};
bst::bst(int v){
	root= new node;
	root->key=v;
	root->left=root->right=NULL,root->parent=NULL;
}
void bst::addnode(int v){
	struct node *temp=root,*t;
	while(temp!=NULL){
		t=temp;
		if(v>temp->key){
			temp=temp->right;
		}
		else{
			temp=temp->left;
		}
	}
	struct node *new_Node=new node;
	new_Node->key=v;
	new_Node->left=new_Node->right=NULL;
	if(t->key<v){
		t->right=new_Node;
	}
	else{
		t->left=new_Node;
	
	}
	new_Node->parent=t;
}
void bst::deletenode(int v){
	if(root==NULL){
		cout<<"No data to delete";
	}
	else{
		struct node *p=root,*c;
		
	}
}
void bst::inorder(struct node *root){
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
}
struct node * bst::root1(){
	return root;
}
int main(){
	bst b(15);
	b.addnode(10);
	b.addnode(8);
	b.addnode(18);
	b.addnode(13);
	b.addnode(17);
	struct node *temp=b.root1();
	b.inorder(temp);
	//b.deletenode(8);
}
