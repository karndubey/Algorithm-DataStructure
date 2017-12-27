#include<bits/stdc++.h>
using namespace std;
class Graph{
    int v;
    int x;
    int max=INT_MIN;
    int weight=INT_MIN;
    bool *leaf;
    list<pair<int,int> > *adj;
    public:
        Graph(int n){
            v=n;
            adj= new list<pair<int,int> >[v+1];
            leaf= new bool[v+1];
            for(int i=0;i<=n;i++)leaf[i]=false;
        }
        void addEdge(int u,int v,int w){
            adj[u].push_back(make_pair(v,w));
            adj[v].push_back(make_pair(u,w));
        }
        void dfs_util(int u,int count,bool visited[]){
        	count++;
        	visited[u]=true;
        	list<pair<int,int> > :: iterator it;
        	for(it=adj[u].begin();it!=adj[u].end();it++){
        		if(!visited[(*it).first]){
        			if(count>max){
        				max=count;
        			}
        			//visited[(*it).first]=true;
        			dfs_util((*it).first,count,visited);
        		}
        	}
        }
        void num_leaf(){
        	for(int i=1;i<=v;i++){
        		if(adj[i].size()==1)leaf[i]=true;
        	}
        }
        void dfs_util_weight(int u,int w,bool visited[],int &weight,int max){
        	if(max==0){
        		if(weight<w)weight=w;
        		//cout<<weight<<endl;
        	}
        	else{
        		list<pair<int,int> > :: iterator it;
        		for(it=adj[u].begin();it!=adj[u].end();it++){
        		if(!visited[(*it).first]){
        			int t=w+(*it).second;
        		//	cout<<t<<" "<<(*it).first<<endl;
        			visited[(*it).first]=true;
        			dfs_util_weight((*it).first,t,visited,weight,max-1);
        		}
        	}	
        	}
        	
        }
        int dfs(){
        		bool visited[v+1];
        		for(int j=0;j<=v;j++)visited[j]=false;
        		num_leaf();
        		dfs_util(1,1,visited);
        		//cout<<max<<endl;
        		if(v==2)max=1;
        		for(int i=1;i<=v;i++){
        			if(leaf[i]){	
        			for(int j=1;j<=v;j++)visited[j]=false;
        			visited[i]=true;
        			dfs_util_weight(i,0,visited,weight,max);
        			}
        		}
        		
        		return weight;
        }
};
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a,b,c;
		cin>>n;
		Graph g(n);
		for(int i=1;i<n;i++){
			cin>>a>>b>>c;
			g.addEdge(a,b,c);
		}
		int ans=g.dfs();
		if(ans>10000)cout<<10000<<" "<<ans;
		else if(ans>1000)cout<<1000<<" "<<ans;
		else if(ans>100)cout<<100<<" "<<ans;
		else cout<<0<<" "<<ans;
		cout<<endl;
	}
}
