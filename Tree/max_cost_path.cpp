#include<bits/stdc++.h>
using namespace std;
class Tree{
	int V;
	list<pair<int,int> > *adj;
	bool *visited;
	public:
		Tree(int v);
		void addEdge(pair<int,int> u,pair<int,int> v);
		int dfs(pair<int, int> u);
};
Tree::Tree(int v){
	V=v;
	adj= new list<pair<int,int> >[v+1];
	visited= new bool[v+1];
	for(int i=1;i<=v;i++){
		visited[i]=false;
	}
}
void Tree:: addEdge(pair<int,int> p,pair<int ,int> q){
	adj[p.first].push_back(q);
	adj[q.first].push_back(p);
}
int Tree::dfs(pair<int, int> u){
	if(!visited[u.first]){
			list<pair<int,int> >:: iterator it=adj[u.first].begin();
			visited[u.first]=true;
			int max=INT_MIN;
			for(it;it!=adj[u.first].end();it++){
				int t=u.second+dfs(*it);
				if(t>max)max=t;
			}
			return max;
	}
	return 0;
}
int main(){
	int v;
	cin>>v;
	Tree tree(v);
	pair<int,int> p,q;
	for(int i=1;i<v;i++){
		cin>>p.first>>p.second>>q.first>>q.second;
		tree.addEdge(p,q);
	}
	 p={1,3};
	cout<<tree.dfs(p);
}
