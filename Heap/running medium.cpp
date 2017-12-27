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
		int parent(int index);
		int extract_max();
		int root();
		void deleteElement(int size);
		void insertElement(int key);
		void bottom_up_heapify(int i);
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
	heap[0]=INT_MAX;
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
		if(key>heap[parent(heap_size)]){
			//cout<<key<<endl;
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
int MaxHeap :: extract_max(){
	int key=root();
	swap(heap[1],heap[heap_size]);
	heap_size--;
	max_heapify(root());
	return key;
}
int MaxHeap :: root(){
	if(heap_size) return heap[1];
	return heap[0];
}
int MaxHeap::parent(int index){
	return index/2;
}
class MinHeap{
	public:
	int *heap;
	int capacity;
	int heap_size;
	public:
		MinHeap(int n);
		void build_heap(int a[],int size);
		void min_heapify(int parent);
		int left(int parent);
		int right(int parent);
		int parent(int index);
		int extract_min();
		int root();
		void deleteElement(int size);
		void insertElement(int key);
		void bottom_up_heapify(int i);
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
MinHeap::MinHeap(int n){
	capacity=n;
	heap_size=0;
	heap= new int[n+1];
	heap[0]=INT_MIN;
}
void MinHeap:: build_heap(int a[],int size){
	heap_size=size;
	for(int i=1;i<=heap_size;i++){
		heap[i]=a[i];
	}
	for(int i=heap_size/2;i>0;i--){
	//	cout<<i<<endl;
		min_heapify(i);
	}
}
int MinHeap:: left(int parent){
	return 2*parent;
}
int MinHeap:: right(int parent){
	return 2*parent+1;
}
void MinHeap:: min_heapify(int parent){
	int l=left(parent);
	int r=right(parent);
	int largest=parent;
	//cout<<l<<" "<<r<<" "<<parent<<endl;
	if(l<=heap_size && heap[l]<heap[parent]){
		largest=l;
	}
	if(r<=heap_size && heap[r]<heap[largest]){
		largest=r;
	}
	//cout<<heap[largest]<<" "<<largest<<endl;
	if(largest!=parent){
		int temp=heap[parent];
		heap[parent]=heap[largest];
		heap[largest]=temp;
		min_heapify(largest);
	}

}
void MinHeap::deleteElement(int index){
	if(index>heap_size)cout<<"Wrong Index"<<endl;
	heap[index]=heap[heap_size];
	heap_size--;
	min_heapify(index);
}
void MinHeap::insertElement(int key){
	if(heap_size==capacity){
		cout<<"Overflow"<<endl;
	}
	else{
		heap_size++;
		heap[heap_size]=key;
		if(key<heap[parent(heap_size)]){
			bottom_up_heapify(heap_size);
		}
	}
}
void MinHeap::bottom_up_heapify(int i){
	int p=i/2;
	if(p>0 && heap[p]>heap[i]){
		swap(heap[p],heap[i]);
		bottom_up_heapify(p);
	}
}
int MinHeap :: extract_min(){
	int key=root();
	swap(heap[1],heap[heap_size]);
	heap_size--;
	min_heapify(root());
	return key;
}
int MinHeap :: root(){
	if(heap_size) return heap[1];
	return heap[0];
}
int MinHeap::parent(int index){
	return index/2;
}
int main(){
	MaxHeap maxheap(1000);
	MinHeap minheap(1000);
	int element;	
	while(true){
		cin>>element;
		 if(minheap.heap_size>maxheap.heap_size){
			if(element <= minheap.root()){
				maxheap.insertElement(element);
			}
			else{
				int key=minheap.extract_min();
				maxheap.insertElement(key);
				minheap.insertElement(element);
			}
		}
		else{
			if(element>=minheap.root()){
				minheap.insertElement(element);
			}
			else{
				int key= maxheap.extract_max();
				maxheap.insertElement(element);
				minheap.insertElement(key);
			}
		}
		cout<<"minheap"<<endl;
		for(int i=1;i<=minheap.heap_size;i++){
			cout<<minheap.heap[i]<<" ";
		}
		cout<<endl;
		cout<<"maxheap"<<endl;
		for(int i=1;i<=maxheap.heap_size;i++){
			cout<<maxheap.heap[i]<<" ";
		}
		cout<<endl;
		cout<<"median "<<minheap.root()<<endl;
	}
}
