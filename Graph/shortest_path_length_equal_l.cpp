#include<bits/stdc++.h>
using namespace std;
struct node{
	long long w=INT_MAX,len=1,count=0;
};
class Graph{
	int v;
	list<pair<int,int> > *adj;
	struct node *D;
	public:
		Graph(int n){
			v=n;
			adj=new list<pair<int,int> >[n+1];
			D= new struct node[n+1];
		}
		void addEdge(int u,int v,int w){
			adj[u].push_back(make_pair(v,w));
		}
		
		void bellman_ford(int s,int l){
			list<pair<int,int> > :: iterator it;
			for(it=adj[s].begin();it!=adj[s].end();it++){
				D[(*it).first].w=(*it).second;
				D[(*it).first].len=1;
				D[(*it).first].count=1;
			}
			D[s].w=0;
			for(int k=2;k<=v;k++){
				for(it=adj[k].begin();it!=adj[k].end();it++){
					if(D[(*it).first].w > D[k].w+(*it).second){
						D[(*it).first].w=D[k].w+(*it).second;
						D[(*it).first].len=D[k].len+1;
						if(D[k].len+1==l)
						D[(*it).first].count=1;
					}
					if(D[(*it).first].w==D[k].w+(*it).second){
						if(D[k].len+1==l){
							D[(*it).first].count+=1;
						}
					}
				}
			}
			for(int i=1;i<=v;i++){
				cout<<D[i].w<<" "<<D[i].len<<" "<<D[i].count<<endl;
			}
		}
};

int main(){
	int v,e,a,b,c,l;
	cin>>v>>e;
	Graph g(v);
	for(int i=0;i<e;i++){
		cin>>a>>b>>c;
		g.addEdge(a,b,c);
	}
	cin>>l;
	g.bellman_ford(1,l);
}
