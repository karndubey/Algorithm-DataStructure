#include<bits/stdc++.h>
using namespace std;
struct node{
	int key;
	struct node *left,*right;
};
struct node* newNode(int val){
	struct node *temp= new node;
	temp->key=val;
	temp->left=temp->right=NULL;
}
// key point the space between between 2 angular bracket > > is req or it will give compilation error
void getVerticalOrder(struct node *root,map<int, vector<int> > &hash,int index){
	if(root==NULL){
		return;
	}
	else{
		//push the root node with given index
		hash[index].push_back(root->key);
		//call left child with index-1 and add it in map
		getVerticalOrder(root->left,hash,index-1);
		//call right child with index+1 and add it in map
		getVerticalOrder(root->right,hash,index+1);
	}
}
void printVerticalOrder(struct node *root){
	map<int,vector<int> > hash;
	int index=0;
	getVerticalOrder(root,hash,index);
	for(map<int,vector<int> >:: iterator it=hash.begin();it!=hash.end();++it){
		for(int i=0;i<it->second.size();i++){
			cout<<it->second[i]<<" ";
		}
		cout<<endl;
	}
}

int main(){
	 struct node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->right->left->right = newNode(8);
    root->right->right->right = newNode(9);
    cout << "Vertical order traversal is n"<<endl;
    printVerticalOrder(root);
}
