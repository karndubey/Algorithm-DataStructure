#include<bits/stdc++.h>
using namespace std;
struct node{
	int value;
	struct node *next;
};
void addNode(struct node **head,int v){
	struct node *temp=new node;
	temp->value= v;
	temp->next=*head;
	*head=temp;
}
/*
	take 2 ptr and update one ptr to nth element
	start with another ptr from head t
	update both ptr till we get last element
	return value of t
*/
int nthlast(struct node *head,int n){
	if (head == null || n < 1) { 
		return 0; 
	}
	struct node *temp=head;
	n--;
	while(n--){
		temp=temp->next;
	}
	struct node *t=head;
	while(temp->next!=NULL){
		t=t->next;
		temp=temp->next;
	}
	return t->value;
}
void deletefrom
int main(){
	struct node *head= new node;
	head->value=8;
	head->next=NULL;
	addNode(&head,7);
	addNode(&head,6);
	addNode(&head,5);
	addNode(&head,4);
	addNode(&head,3);
	addNode(&head,2);
	addNode(&head,1);
	cout<<nthlast(head,4);				
}
