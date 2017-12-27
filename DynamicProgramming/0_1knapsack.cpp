#include<bits/stdc++.h>
using namespace std;
int knapsack(int cost[],int weight[],int n,int c){
	int profit[n+1][c+1];
	for(int i=0;i<=n;i++)profit[i][0]=0;
	for(int i=0;i<=c;i++)profit[0][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=c;j++){
			if(j>=weight[i-1] && profit[i-1][j]<cost[i-1]+profit[i-1][j-weight[i-1]]){
				profit[i][j]=cost[i-1]+profit[i-1][j-weight[i-1]];
			}
			else{
				profit[i][j]=profit[i-1][j];
			}
		}
	}
	int i=n,j=c;
	bool taken[n];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=c;j++){
			cout<<profit[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<n;i++)taken[i]=false;
	while(j>0 && i>0){
		if(profit[i][j]==profit[i-1][j]){
			i--;
		}
		else{
			taken[i-1]=true;
			j--;
		}
	}
	for(int i=0;i<n;i++){
		if(taken[i])cout<<cost[i]<<" ";
	}
	cout<<endl;
	return profit[n][c];
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,capacity;
		cin>>n>>capacity;
		int cost[n];
		int weight[n];
		for(int i=0;i<n;i++){
			cin>>cost[i];
		}
		for(int i=0;i<n;i++){
			cin>>weight[i];
		}
		cout<<knapsack(cost,weight,n,capacity);
	}
	
}
