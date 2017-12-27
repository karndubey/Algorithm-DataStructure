#include<bits/stdc++.h>
using namespace std;
struct node{
	int key;
	struct node *left,*right;
	int height;
};
int max(int a,int b){
	return (a > b)? a : b;
}
int height(struct node *N){
	if(N==NULL)return 0;
	return N->height;
}
struct node* newNode(int val){
	struct node *newNode= new node;
	newNode->key=val;
	newNode->left=NULL;
	newNode->right=NULL;
	newNode->height=1;
	return newNode;
}
int getBalance(struct node* n){
	if(n==NULL){
		return 0;
	}
	return height(n->left)-height(n->right);
}
struct node *rightRotation(struct node *z){
	struct node *y=z->left;
	struct node *T3=y->right;
	y->right=z;
	z->left=T3;
	z->height=max(height(z->left),height(z->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;
}
struct node *leftRotation(struct node *z){
	struct node *y=z->right;
	struct node *T3=y->left;
	y->left=z;
	z->right=T3;
	z->height=max(height(z->left),height(z->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	return y;
}
struct node *insert(struct node *n,int key){
	
	if(n==NULL){
	//	cout<<key<<endl;
		return newNode(key);
	}
	 if(key > n->key){
	 	//cout<<n->key<<endl;
		n->right=insert(n->right,key);
	}
	else if(key<n->key){
		n->left=insert(n->left,key);
	}
	else{
		return n;
	}
	n->height=1+max(height(n->left),height(n->right));
	int balance = getBalance(n);
	//cout<<balance<<endl;
	//Left-Left rotation
	if(balance>1 && key <n->left->key){
		return rightRotation(n);
	}
	//Right-Right rotation
	if(balance <-1 && key>n->right->key){
		return leftRotation(n);
	}
	//Left-Right rotation
	if(balance >1 && key>n->left->key){
		n->left=leftRotation(n->left);
		return rightRotation(n);
	}
	//Right-Left Rotation
	if(balance<-1 && key<n->right->key){
		n->right=rightRotation(n->right);
		return leftRotation(n);
	}
	return n;
}
struct node *minvalue(struct node *root){
	if(!root->left && !root->right){
		return root;
	}
	return minvalue(root->left); 
}
struct node *delete_node(struct node *root,int key){
	if(root==NULL)return root;
	else{
		if(root->key > key){
			root->left= delete_node(root->left,key);
		}
		else if(root->key <key){
			root->right=delete_node(root->right,key);
		}
		else{
			if(root->left==NULL || root->right==NULL){
				struct node *temp=root->left? root->left:root->right;
				if(!temp){
					temp=root;
					root=NULL;
				}
				else{
					*root=*temp;
				}
				delete(temp);
			}
			else{
				struct node *temp=minvalue(root->right);
				root->key=temp->key;
				// Delete the inorder successor
           		 root->right = delete_node(root->right, temp->key);
			}
			if(root==NULL)
				return root;
			root->height= 1+max(height(root->left),height(root->right));
			int balance = getBalance(root);
			// Left Left Case
    		if (balance > 1 && getBalance(root->left) >= 0)
       		 return rightRotation(root);
 
    		// Left Right Case
    		if (balance > 1 && getBalance(root->left) < 0)
    		{
       		 root->left =  leftRotation(root->left);
        		return rightRotation(root);
    		}
 
    		// Right Right Case
    		if (balance < -1 && getBalance(root->right) <= 0)
        		return leftRotation(root);
 
    		// Right Left Case
    		if (balance < -1 && getBalance(root->right) > 0)
    		{
        		root->right = rightRotation(root->right);
        		return leftRotation(root);
    		}
 
    	return root;
		}
	}
}
int find_node(struct node *root,int start_time){
	if(root){
		if(root->key >start_time){
			return find_node(root->left,start_time);
		}
		else{
			return root->key;
		}
	}
	return -1;
}
struct job{
	int start_time,finish_time;
};
bool sortby(struct job a,struct job b){
	return a.start_time<b.start_time;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct job a[n];
		for(int i=0;i<n;i++){
			cin>>a[i].start_time>>a[i].finish_time;
		}
		sort(a,a+n,sortby);
		struct node *root=NULL;
		 root = insert(root, a[0].finish_time);
		 int num_machine=1;
		 for(int i=1;i<n;i++){
		 	int t=find_node(root,a[i].start_time);
			 if(t==-1){
			 	num_machine++;
			 	root=insert(root,a[i].finish_time);
			 }
			 else{
			 	root=delete_node(root,t);
			 	root=insert(root,a[i].finish_time);
			 } 
		 }
		 cout<<num_machine<<endl;
	}
}
