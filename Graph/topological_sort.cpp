#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,st=0,ft=0;
};
bool compbysec(pair<int,int>p,pair<int,int> q){
	return p.second>q.second;
}
class Graph{
	int v;
	list<int> *adj;
	bool *visited;
	int count;
	int *st;
	vector<pair<int,int> > ft;
	public:
		Graph(int n){
			v=n;
			adj= new list<int>[v+1];
			visited= new bool[n+1];
			st=new int[n+1];
			count=0;
		}
		void addEdge(int u, int v){
			adj[u].push_back(v);
			//adj[v].push_back(u);
		}
		void dfs_util(int u){
			//cout<<u<<" : ";
			list<int> :: iterator it;
			for(it=adj[u].begin();it!=adj[u].end();it++){
				if(!visited[(*it)]){
				
					visited[(*it)]=true;
					st[*it]=++count;
					dfs_util(*it);
				}
			}
			//cout<<u<<endl;
			ft.push_back(make_pair(u,++count));	
		}
		void dfs(int u){
			st[u]=++count;
			visited[u]=true;
			dfs_util(u);
			//ft.push_back(make_pair(u,++count));
			sort(ft.begin(),ft.end(),compbysec);
			for(int i=0;i<=v;i++){
				cout<<ft[i].first<<" "<<ft[i].second<<endl;
			}	
		}
};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,e,a,b;
		cin>>n>>e;
		Graph g(n);
		for(int i=0;i<e;i++){
			cin>>a>>b;
			g.addEdge(a,b);
		}
		g.dfs(1);
	}
}
