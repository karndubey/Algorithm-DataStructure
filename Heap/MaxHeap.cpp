#include<bits/stdc++.h>
using namespace std;
class MaxHeap{
	public:
	int *heap;
	int capacity;
	int heap_size;
	public:
		MaxHeap(int n);
		void build_heap(int a[],int size);
		void max_heapify(int parent);
		int left(int parent);
		int right(int parent);
		void deleteElement(int size);
		void insertElement(int key);
		void bottom_up_heapify(int i);
		void change_key(int i,int x);
		int parent(int index);
		void print(int k){
			for(int i=1;i<=k;i++){
				cout<<heap[i]<<" ";
			}
			cout<<endl;
			/*for(int i=1;i<=heap_size;i++){
				cout<<heap[i]<<endl;
			}*/
		}
};
MaxHeap::MaxHeap(int n){
	capacity=n;
	heap_size=0;
	heap= new int[n+1];
}
void MaxHeap:: build_heap(int a[],int size){
	heap_size=size;
	for(int i=1;i<=heap_size;i++){
		heap[i]=a[i];
	}
	for(int i=heap_size/2;i>0;i--){
	//	cout<<i<<endl;
		max_heapify(i);
	}
}
int MaxHeap:: left(int parent){
	return 2*parent;
}
int MaxHeap:: right(int parent){
	return 2*parent+1;
}
void MaxHeap:: max_heapify(int parent){
	int l=left(parent);
	int r=right(parent);
	int largest=parent;
	//cout<<l<<" "<<r<<" "<<parent<<endl;
	if(l<=heap_size && heap[l]>heap[parent]){
		largest=l;
	}
	if(r<=heap_size && heap[r]>heap[largest]){
		largest=r;
	}
	//cout<<heap[largest]<<" "<<largest<<endl;
	if(largest!=parent){
		int temp=heap[parent];
		heap[parent]=heap[largest];
		heap[largest]=temp;
		max_heapify(largest);
	}

}
void MaxHeap::deleteElement(int index){
	if(index>heap_size)cout<<"Wrong Index"<<endl;
	heap[index]=heap[heap_size];
	heap_size--;
	max_heapify(index);
}
void MaxHeap::insertElement(int key){
	if(heap_size==capacity){
		cout<<"Overflow"<<endl;
	}
	else{
		heap_size++;
		heap[heap_size]=key;
		if(key>parent(heap_size)){
			bottom_up_heapify(heap_size);
		}
	}
}
void MaxHeap::bottom_up_heapify(int i){
	int p=i/2;
	if(p>0 && heap[p]<heap[i]){
		swap(heap[p],heap[i]);
		bottom_up_heapify(p);
	}
}
int MaxHeap::parent(int index){
	return index/2;
}
void MaxHeap::change_key(int i,int x){
	heap[i]=x;
	if(heap[i]>heap[parent(i)]){
		bottom_up_heapify(i);
	}
	else{
		max_heapify(i);
	}
}
int main(){
	// maximum element in array i.e. capacity is n
	// k no of elements inserted in begining
	int n,k;
		cin>>n>>k;
		
		int a[n+1];
		for(int i=1;i<=k;i++){
			cin>>a[i];
		}
		MaxHeap h(n);
		h.build_heap(a,k);
		h.print(k);
		
}
