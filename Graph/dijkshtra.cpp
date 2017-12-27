#include<bits/stdc++.h>
using namespace std;

class Graph{
	int v;
	list<pair<int,int> > *adj;
	priority_queue< pair<int,int>, vector<pair<int,int> > > minheap;
	public:
		Graph(int n){
			v=n;
			adj=new list<pair<int,int> >[n+1];
		}
		void addEdge(int u,int v,int w){
			adj[u].push_back(make_pair(v,w));
		}
		void shortest_path(int u){
			vector<int> dist(v+1,INT_MAX);
			dist[u]=0;
			pair<int,int> temp;
			minheap.push(make_pair(u,0));
			while(!minheap.empty()){
				temp=minheap.top();
				minheap.pop();
				list<pair<int,int> >:: iterator it;
				for(it=adj[temp.first].begin();it!=adj[temp.first].end();it++){
					if(dist[(*it).first]>dist[temp.first]+(*it).second){
						dist[(*it).first]=dist[temp.first]+(*it).second;
						minheap.push(make_pair((*it).first,dist[(*it).first]));
					}
				}
				for(int i=1;i<=v;i++){
					cout<<dist[i]<<" ";
				}
				cout<<endl;
			}
		}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e,a,b,w;
		cin>>n>>e;
		Graph g(n);
		for(int i=0;i<e;i++){
			cin>>a>>b>>w;
			g.addEdge(a,b,w);
		}
		g.shortest_path(1);
	}
}
