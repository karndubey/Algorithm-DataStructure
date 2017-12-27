#include<bits/stdc++.h>
using namespace std;
bitset<>

int main(){
	int n,u,v,ans=0;
	cin>>n;
	Graph g(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>graph[i][j];
		}
	}

	//g.print();
	cout<<g.dfs(4);	
}
