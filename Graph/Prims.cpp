#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
};
	bool operator<(const node& a, const node& b) {
  	return a.w > b.w;
};
priority_queue< struct node,vector<struct node> > min_heap;
class Graph{
	int v;
	list<pair<int,int> > *adj;
	public:
		Graph(int n){
			v=n;
			adj= new list<pair<int,int> >[n+1];
		}
		void addEdge(int u,int v,int w){
			adj[u].push_back(make_pair(v,w));
			//adj[v].push_back(make_pair(u,w));
		}
		void build_heap(){
			list<pair<int,int> > :: iterator it;
			for(int i=1;i<=v;i++){
				for(it=adj[i].begin();it!=adj[i].end();it++){
					struct node *temp=new node;
					temp->u=i;
					temp->v=(*it).first;
					temp->w=(*it).second;
					min_heap.push(*temp);
				}
			}
		}
		void mst(){
			bool visited[v+1];
			bool path[v+1][v+1];
			for(int i=1;i<=v;i++)
				for(int j=1;j<=v;j++)path[i][j]=false;
			for(int i=1;i<=v;i++)visited[i]=0;
			int count=0;
			int weight=0;
			while(count<v-1){
				//struct node *temp;
				const struct node temp=min_heap.top();
				if(!visited[temp.u] || !visited[temp.v]){
					visited[temp.u]=visited[temp.v]=true;
					count++;
					weight+=temp.w;
					path[temp.u][temp.v]=true;
				}
				min_heap.pop();
			}
			for(int i=1;i<=v;i++){
				for(int j=1;j<=v;j++){
					if(path[i][j])cout<<i<<"------>"<<j<<endl;
				}
			}
			cout<<"Weight is : "<<weight<<endl;
		}
};
int main(){
	int n,e;
	cin>>n>>e;
	Graph g(n);
	for(int i=0;i<e;i++){
		int a,b,c;
		cin>>a>>b>>c;
		g.addEdge(a,b,c);
	}
	g.build_heap();
	g.mst();
}
