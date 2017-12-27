#include<bits/stdc++.h>
using namespace std;
int a[1000][1000];
int mincost(int i,int j,int m,int n){
	int cost[m+1][n+1];
	cost[0][0]=a[0][0];
	for(int j=1;j<=n;j++)cost[0][j]=cost[0][j-1]+a[0][j];
	for(int i=1;i<=m;i++){
		for(int j=0;j<=n;j++){
			if(j==0){
				cost[i][j]=cost[i-1][j]+a[i][j];
			}
			else{
				cost[i][j]=a[i][j]+min(cost[i-1][j],min(cost[i][j-1],cost[i-1][j-1]));
			}
		}
	}
	
	return cost[m][n];
}
int main(){
	int x,y;
	cin>>x>>y;
	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin>>a[i][j];
		}
	}
	
	int m,n;
	cin>>m>>n;
	cout<<mincost(0,0,m,n)<<endl;
	cout<<mincost(0,0,1,2)<<endl;
	cout<<mincost(0,0,2,1)<<endl;
}
