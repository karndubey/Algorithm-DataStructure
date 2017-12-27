#include<bits/stdc++.h>
using namespace std;
class Graph{
	list<long long> *adj;
	public:
		Graph(long long n){
			adj= new list<long long>[n];
		}
		void insert(long long u, long long v){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		long long dfs(bool visited[],int root){
			visited[root]=true;
				list<long long> :: iterator it;
				for(it=adj[root].begin();it!=adj[root].end();it++){
					if(!visited[*it]){
						visited[*it]=true;
						dfs(visited,*it);
					}
				}
				return 1;
		}
};

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n,q,ans=0;
		scanf("%lld %lld",&n,&q);
		long long u,v;
		Graph graph(n);
		while(q--){
			scanf("%lld %lld",&u,&v);
			graph.insert(u,v);
		}
		bool visited[n];
		for(int i=0;i<n;i++){
			visited[i]=false;
		}
		for(int i=0;i<n;i++){
			if(!visited[i]){
				ans+=graph.dfs(visited,i);
			}
		}
		cout<<ans<<endl;
	}	
}
