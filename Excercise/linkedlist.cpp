#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	struct node *next;
};
struct node *start=NULL;
void add(int a){
	if(start==NULL){
		start=new node;
		start->a=a;
		start->next=NULL;
	}
	else{
		struct node *temp= new node;
		temp->a=a;
		temp->next=start;
		start=temp;
	}
}
struct node * reversal(struct node *a,struct node *temp){
	if(temp->next==NULL){
		return temp->next=a;
	}
	else{
		reversal(temp,temp->next);
		temp->next=a;
	}
	if(a==start){
		start->next=NULL;
	}
}
int main(){
	add(5);
	add(4);
	add(3);
	add(2);
	add(1);
	struct node *temp;
	
	start=reversal(start,start->next);
	temp=start;
	while(temp!=NULL){
		cout<<temp->a<<" ";
		temp=temp->next;
	}
}
