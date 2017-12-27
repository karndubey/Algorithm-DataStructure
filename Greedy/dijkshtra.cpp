#include<bits/stdc++.h>
//#include "MinHeap.cpp"
using namespace std;

struct HeapNode{
	int v,dist;
};
struct MinHeap{
	int size;
	int capacity;
	int *pos;
	struct HeapNode **array;
};
struct MinHeap * createMinHeap(int v){
	struct MinHeap *minheap= new MinHeap;
	minheap->size=0;
	minheap->capacity=v;
	minheap->pos= new int[v];
	minheap->array =(struct HeapNode**) malloc(v * sizeof(struct HeapNode*));
    return minheap;
}
struct HeapNode *newNode(int v,int dist){
	HeapNode *t= new HeapNode;
	t->v=v;
	t->dist=dist;
	return t;
}
void swap(struct HeapNode **a, struct HeapNode **b){
	struct HeapNode *t=*a;
	*a=*b;
	*b=*a;
}
void minHeapify(struct MinHeap *minheap,int id){
	int l=id*2+1;
	int r=id*2+2;
	int smallest=id;
	if(l<=minheap->size && minheap->array[id]->dist>minheap->array[l]->dist){
		smallest=l;
	}
	if(r<=minheap->size && minheap->array[smallest]->dist> minheap->array[r]->dist){
		smallest=r;
	}
	if(smallest!=id){
		HeapNode *small= minheap->array[smallest];
		HeapNode *idNode= minheap->array[id];
		minheap->pos[small->v]=id;
		minheap->pos[idNode->v]=smallest;
		swap(&minheap->array[smallest],&minheap->array[id]);
		minHeapify(minheap,smallest);
	}
}
void bottom_up_heapify(struct MinHeap *minheap, int i){
	int p=i/2;
	if(p>0 && minheap->array[i]->dist< minheap->array[p]->dist){
		minheap->pos[minheap->array[i]->v]=p;
		minheap->pos[minheap->array[p]->v]=i;
		swap(&minheap->array[i],&minheap->array[p]);
		bottom_up_heapify(minheap,p);
	}
}
void decreaseKey(struct MinHeap *minheap,int v,int w){
	int p=minheap->pos[v];
	minheap->array[p]->dist=w;
	bottom_up_heapify(minheap,p);
}
struct HeapNode *extractmin(){
	
}
class Graph{
	int V;
	list<pair<int,int> > *adj;
	public:
		Graph(int v){
			V=v;
			adj= new list<pair<int,int> >;
		}
		void addEdge(int u,int v,int w){
			adj[u].push_back(make_pair(v,w));
		}
		void dijkshtra(int s){
			
		}
};

int main(){
	int v=5;
	Graph g(5);
	g.addEdge(0,2,3);
	g.addEdge(0,4,6);
	g.addEdge(2,4,2);
	g.addEdge(2,3,9);
	g.addEdge(4,5,4);
	g.addEdge(5,2,2);
	g.addEdge(5,3,1);
	g.dijkshtra(0);
}
