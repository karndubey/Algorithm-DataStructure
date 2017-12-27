#include<bits/stdc++.h>
using namespace std;
class MaxHeap{
	int *heap;
	int capacity;
	int heap_size;
	public:
		MaxHeap(int n);
		void build_heap(int a[]);
		void max_heapify(int parent);
		int left(int parent);
		int right(int parent);
		void print(int k){
			for(int i=1;i<=k;i++){
				cout<<heap[1]<<" ";
				swap(heap[1],heap[heap_size]);
				heap_size--;
				max_heapify(1);
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
void MaxHeap:: build_heap(int a[]){
	heap_size=capacity;
	for(int i=1;i<=capacity;i++){
		heap[i]=a[i];
	}
	for(int i=capacity/2;i>0;i--){
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

int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n+1];
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		MaxHeap h(n);
		h.build_heap(a);
		h.print(k);
	}
}
