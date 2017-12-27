#include<bits/stdc++.h>
using namespace std;
long long ans=0;
void addEdge(vector<int> tree[],int u,int v){
	tree[u].push_back(v);
	tree[v].push_back(u);
}
void dfs(vector<int> tree[],bool visited[],int u,int k){
	if(k==0){
		ans++;
		return;
	}
	else{
		vector<int> ::iterator it;
		for(it=tree[u].begin();it!=tree[u].end();it++){
			if(!visited[*it]){
				visited[*it]=true;
				dfs(tree,visited,*it,k-1);
			}
			
		}
	}
}
int main(){
	int n,k,u,v;
	cin>>n>>k;
	vector<int> tree[n+1]; 
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		addEdge(tree,u,v);
    }
    bool visited[n+1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)visited[j]=false;
		visited[i]=true;
		dfs(tree,visited,i,k);
	}
	cout<<ans/2;
}
