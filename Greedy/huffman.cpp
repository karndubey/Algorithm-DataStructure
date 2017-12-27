#include<bits/stdc++.h>
using namespace std;
struct node{
	int k;
	struct node *left,*right;
};
struct node* newNode(int key){
	struct node *temp=new node;
	temp->key=key;
	temp->left=temp->right=NULL;
}
struct node *insert(struct node *root,int key){
	if(!root){
		struct node *t=newNode(key);
		return root;
	}
	else if(root->key >=key){
		root->right=insert(root->right,key);
	}
	else{
		root->left=insert(root->left,key);
	}
	return root;
}
void preorder(struct node *root,int i ){
	if(!root->left && !root->right){
		cout<<" ";
		return;
	}
	else if(root){
		cout<<i;
		preorder(root->left,0);
		preorder(root->left,1);
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;// s is string that contain all unique char that can occur in text;
		priority_queue<int,vector<int>,greater<int> > minheap;
		cin>>s;
		int freq[i],num_of_bits[s.length()];
		for(int i=0;i<s.length();i++){
			cin>>freq[i];
		}
		sort(freq,freq+n);
		for(int i=0;i<s.length();i++)min_heap.push(freq[i]);
		while(!min_heap.empty()){
			int a=min_heap.top();
			min_heap.pop();
			int b=min_heap.top();
			min_heap.pop();
			if(min_heap)
		}
	}
}
