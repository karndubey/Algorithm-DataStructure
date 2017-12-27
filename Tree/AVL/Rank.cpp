#include<bits/stdc++.h>
using namespace std;
struct node {
	int key;
	int height;
	int num;
	int sum;
	int min;
	int max;
	int mingap;
	struct node *left,*right;
};
class AVL{
	struct node *root;
	public:
		AVL(){
			root=NULL;
		}
		struct node *insertNode(struct node *root,int key,int min,int max);
		struct node *deleteNode(struct node *root,int key);
		struct node *leftRotate(struct node *z);
		struct node *rightRotate(struct node *z);
		int height(struct node *root);
		int getBalance(struct node *root);
		int getkey(struct node *root){
			if(root) return root->key;
			return 0;
		}
		int rank(struct node *root,int x);
		int number(struct node *root);
		int findrank(struct node *root,int k);
		int range(struct node *root,int x,int y);
		long long sum(struct node *root,int x,int y);
		int getSum(struct node *root);
		struct node *successor(struct node *root);
		int prefixSum(struct node *root,int x);
		void preorder(struct node *root){
			if(root!=NULL){
				cout<<root->key<<" "<<root->sum<<endl;
				preorder(root->left);
				preorder(root->right);
			}
			
		}
};
int AVL :: number(struct node *root){
	if(root==NULL)return 0;
	return root->num;
}
struct node * AVL::insertNode(struct node *root,int key,int min,int max){
	if(root==NULL){
		struct node *temp = new node;
		temp->key=key;
		temp->left=temp->right=NULL;
		temp->height=1;
		temp->num=1;
		temp->sum=key;
		temp->min=min<=key ? min : key;
		temp->max=max>=key ? max :key;
		temp->mingap=INT_MAX;
		root=temp;
		return root;
	}
	else if(key>root->key){
		root->right=insertNode(root->right,key,min,max);
	}
	else if(key <root->key){
		root->left=insertNode(root->left,key,min,max);
		root->sum+=key;
	}
	else{
		return root;
	}
	root->height=1+std::max(height(root->left),height(root->right));
	root->num=1+number(root->left)+number(root->right);
	root->sum=root->key+getSum(root->left)+getSum(root->right);
	if(key < root->min){
		cout<<key<<"  "<<root->min<<endl;
		root->min=key;
	}
	else if(root->max < key)root->max=key;
	root->mingap=std::min(root->mingap,std::min(root->key-getkey(root->left),abs(getkey(root->right)-root->key)));
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
if(root==NULL)return root;
	else{
		if(root->key > key){
			root->left= deleteNode(root->left,key);
		}
		else if(root->key <key){
			root->right=deleteNode(root->right,key);
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
				struct node *temp=successor(root->right);
				root->key=temp->key;
				// Delete the inorder successor
           		 root->right = deleteNode(root->right, temp->key);
			}
			if(root==NULL)
				return root;
			
			root->height= 1+max(height(root->left),height(root->right));
			root->num=1+number(root->left)+number(root->right);
			root->sum=root->key+getSum(root->left)+getSum(root->right);
			int balance = getBalance(root);
			// Left Left Case
    		if (balance > 1 && getBalance(root->left) >= 0){
    			return rightRotate(root);
    		}
       		 
 
    		// Left Right Case
    		if (balance > 1 && getBalance(root->left) < 0)
    		{
       		 root->left =  leftRotate(root->left);
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
	}
}
struct node * AVL :: successor(struct node *root){
	struct node *current=root;
	while(current->left!=NULL){
		current=current->left;
	}
	//cout<<current->key<<endl;
	return current;
}

struct node * AVL::rightRotate(struct node *z){
	struct node *y=z->left;
	struct node *T3=y->right;
	y->right=z;
	z->left=T3;
	z->height=max(height(z->left),height(z->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	z->num=1+number(z->left)+number(z->right);
	y->num=1+number(y->left)+number(y->right);
	z->sum=z->key+getSum(z->left)+getSum(z->right);
	y->sum=y->key+getSum(y->left)+getSum(y->right);
	return y;
}
struct node * AVL::leftRotate(struct node *z){
	struct node *y=z->right;
	struct node *T3=y->left;
	y->left=z;
	z->right=T3;
	z->height=max(height(z->left),height(z->right))+1;
	y->height=max(height(y->left),height(y->right))+1;
	z->num=1+number(z->left)+number(z->right);
	y->num=1+number(y->left)+number(y->right);
	z->sum=z->key+getSum(z->left)+getSum(z->right);
	y->sum=y->key+getSum(y->left)+getSum(y->right);
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
int AVL:: rank(struct node *root,int x){
	//cout<<root->key<<" ";
		if(root==NULL) return 0;
		if(root->key > x){
			int temp= number(root->right)+1;
			return temp+rank(root->left,x);
		}
		return rank(root->right,x);
}
int AVL :: findrank(struct node *root,int k){
	if(k > number(root)) return 0;
	int r= number(root->right);
	if(r+1==k) return root->key;
	else if(r+1<k){
		k=k-(r+1);
		return findrank(root->left,k);	
	}
	else{
		findrank(root->right,k);
	}
}
int AVL::range(struct node *root,int x,int y){
	int a=rank(root,y);
	int b=rank(root,x);
	//cout<<b<<" "<<a<<endl;
	return b-a;
}
int AVL::getSum(struct node *root){
	if(root==NULL)return 0;
	return root->sum;
}
int AVL:: prefixSum(struct node *root,int x){
	if(root){
		if(root->key <x){
			return root->sum-getSum(root->right)+prefixSum(root->right,x);
		}
		else if(root->key >x){
			return prefixSum(root->left,x);
		}
		else{
			return root->sum-getSum(root->right);
		}		
	}
		return 0;
}
int main(){
	AVL tree;
	struct node *root=NULL;
	root=tree.insertNode(root,10,10,10);
	root=tree.insertNode(root,20,root->min,root->max);
	root=tree.insertNode(root,30,root->min,root->max);
	root=tree.insertNode(root,40,root->min,root->max);
	root=tree.insertNode(root,50,root->min,root->max);
	root=tree.insertNode(root,25,root->min,root->max);
	cout<<1+tree.rank(root,40)<<endl;
	cout<<tree.findrank(root,5)<<endl;
	cout<<tree.range(root,25,60)<<endl;
	cout<<tree.prefixSum(root,30)<<endl;
	cout<<root->min<<" "<<root->max<<" "<<root->mingap<<endl;
	root=tree.deleteNode(root,10);
	root=tree.deleteNode(root,30);
	cout<<tree.prefixSum(root,30)<<endl;
	//cout<<root->min<<" "<<root->max<<" "<<root->mingap<<endl;
	tree.preorder(root);
}
