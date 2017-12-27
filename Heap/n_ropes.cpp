#include<bits/stdc++.h>
using namespace std;
class MinHeap{
	public:
	int capacity;
	int size;
	int *heap;
	public:
	MinHeap(int c){
		capacity=c;
		size=-1;
		heap=new int[c];
	}
	void build_heap(int a[]){
		for(int i=0;i<capacity;i++){
			heap[++size]=a[i];
		}
		for(int i=capacity/2;i>=0;i--){
			min_heapify(i);
		}
	}
	void min_heapify(int i){
		int l=left(i);
		int r=right(i);
		int largest=i;
		//cout<<l<<" "<<r<<" "<<size<<endl;
		if(l<=size && heap[largest]>heap[l]){
			largest=l;
		}
		if(r<=size && heap[largest]>heap[r]){
			largest=r;		
		}
		if(largest!=i){
			swap(heap[largest],heap[i]);
			min_heapify(largest);
		}
	}
	void insertElement(int key){
	if(size==capacity){
		cout<<"Overflow"<<endl;
	}
	else{
		heap[++size]=key;
		if(key<parent(size)){
			bottom_up_heapify(size);
		}
		}
	}
	void bottom_up_heapify(int i){
	int p=i/2;
	if(p>=0 && heap[p]<heap[i]){
		swap(heap[p],heap[i]);
		bottom_up_heapify(p);
		}
	}
	int parent(int index){
	return index/2;
	}
	int left(int index){
		return 2*index+1;
	}
	int right(int index){
		return 2*index+2;
	}
	int extract_min(){
		int temp=heap[0];
		swap(heap[0],heap[size]);
		size--;
		min_heapify(0);
		return temp;
	}	
};


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,sum=0;
		cin>>n;
		MinHeap minheap(n);
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		minheap.build_heap(a);
		while(minheap.size){
			int u=minheap.extract_min();
			int v=minheap.extract_min();
			cout<<u<<" "<<v<<endl;
			sum+=(u+v);
			minheap.insertElement(u+v);
		}
		cout<<sum<<endl;
	}
}
