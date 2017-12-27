#include<bits/stdc++.h>
using namespace std;
map<int,int> mp;
class heap{
	int V;
	list<long long> *adj;
	public :
		heap(int v);
		void build_heap(int n);
		void addEdge(int u,int v);
		void inorder(){
		list<long long> :: iterator it;
		for(int j=1;j<=V;j++){
				cout<<j<<endl;
				for(it=adj[j].begin();it!=adj[j].end();it++){
			 cout<<(*it)<<" ";
		}
		cout<<endl;	
	}	
		}
	
};
heap :: heap(int v){
	V=v;
	adj= new list<long long>[V+1];
}
void heap:: build_heap(int n){
	if(n>V/2){
		adj[n].push_back(n/2);
		build_heap(--n);
	}
	else if(n==1){
		vector<long long> l;
		adj[n].push_back(n*2);
		adj[n].push_back(n*2+1);
	}
	else {
		vector<long long> l;
		adj[n].push_back(n/2);
		adj[n].push_back(n*2);
		if((n*2+1)<=V){
			adj[n].push_back(n*2+1);
		}
		//adj[n].push_back(l);
		build_heap(--n);
	}
	
}
void heap :: addEdge(int u,int v){
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int get_id(int x){
	if(!mp[x])mp[x]=(int)mp.size();
	return mp[x];
}
int main(){
	long long n,m;
	cin>>n>>m;
	heap h(n);
	h.build_heap(n);
	
	while(m--){
		int a,b;
		cin>>a>>b;
		h.addEdge(a,b);	
	}
	cout<<get_id(1);
}
