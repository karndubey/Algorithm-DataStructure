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
void lastaddNode(struct node **last,int v){
	if(*last!=NULL){
	struct node *temp=new node;
	temp->value= v;
	temp->next=NULL;
	*last->next=temp;
	*last=temp;
	}
	else{
	*last->value=v;
	*last>next=NULL;
	}
}
struct node *addlist(struct node *head1, struct node *head2){
	struct node *head3= new node;
	struct node *last=new node;
	last=head3;
	struct node *t= head1;
	struct node *t1=head2;
	int carry=0;
	while(t!=NULL || t1!=NULL){
	   carry=(carry+t->value+t1->value);
	   lastaddNode(&last,carry%10); 	 
	   carry/=10;
	   t=t->next;
	   t1=t1->next; 
	}
	if(t==NULL){
		t=t1;
	}
	while(t!=NULL){
		carry=(carry+t->value);
	   lastaddNode(&last,carry%10); 	 
	   carry/=10; 
	   t=t->next;
	}
	if(carry){
		lastaddNode(&last,carry%10); 
	}
	return head3;
}
int main(){
	
}
