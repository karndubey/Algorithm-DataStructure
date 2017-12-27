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
	list<int> *g_prime;
	bool *visited;
	int count;
	int *st;
	vector<pair<int,int> > ft;
	public:
		Graph(int n){
			v=n;
			adj= new list<int>[v+1];
  			g_prime=new list<int>[v+1];
			visited= new bool[n+1];
			st=new int[n+1];
			count=0;
		}
		void addEdge(int u, int v){
			adj[u].push_back(v);
			g_prime[v].push_back(u);
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
			/*for(int i=0;i<ft.size();i++){
				cout<<ft[i].first<<" "<<ft[i].second<<" ";
			}*/	
		}
		void strong_comp(bool visit[],int u,list<int> *comp,int index){
			list<int> :: iterator it;
			comp[index].push_back(u);
			for(it=g_prime[u].begin();it!=g_prime[u].end();it++){
				if(!visit[*it]){
					visit[*it]=true;
					strong_comp(visit,*it,comp,index);
				}
			}
		}
		void strongly_connected_component(){
			bool visit[v+1];
			list<int> *comp=new list<int>[v];
			int index=-1;
			for(int i=0;i<=v;i++)visit[i]=false;
			for(int i=0;i<ft.size();i++){
				if(!visit[ft[i].first]){
					//cout<<ft[i].first<<endl;
					visit[ft[i].first]=true;
					index++;
					strong_comp(visit,ft[i].first,comp,index);
				}
			}
			list<int> :: iterator it;
			for(int i=0;i<=index;i++){
				for(it=comp[i].begin();it!=comp[i].end();it++){
					cout<<*it<<" ";
				}
				cout<<endl;
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
		g.strongly_connected_component();
	}
}
