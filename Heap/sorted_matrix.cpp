#include<bits/stdc++.h>
using namespace std;
int matrix[100][100];
int N=5;
struct node{
		int value,r,c;
};
void min_heapify(node a[],int i,int n){
	if(i==0) return;
	int left=2*i;
	int right=2*i+1;
	int largest=i;
	//cout<<a[largest].value<<" ";
	if(n>=left && a[largest].value>a[left].value){
		largest=left;
	}
	if(n>=right && a[largest].value > a[right].value){
		largest=right;
	}
	//cout<<largest<<" ";
	if(largest!=i){
		int temp=a[i].value;
		a[i].value=a[largest].value;
		a[largest].value=temp;
		min_heapify(a,largest,n);
	}
}
void build_heap(node a[],int n){
	for(int i=n/2;i>0;i--){
		//cout<<i<<" ";
		min_heapify(a,i,n);
	}
}
void sorted_sequence(int n){
	struct node * a= new node[6];
	for(int i=1;i<n+1;i++){
		a[i].value
	}
	build_heap()
}
int main(){
	
	int j=5;
	int mat[5][5] = { {10, 20, 30, 40},
                    {15, 25, 35, 45},
                    {27, 29, 37, 48},
                    {32, 33, 39, 50},
                  };
	sorted_sequence(a,5);
	for(int i=1;i<6;i++){
		cout<<a[i].value<<" ";
	}
	
}
