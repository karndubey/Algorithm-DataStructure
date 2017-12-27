#include<bits/stdc++.h>
using namespace std;
int ks(int cost[],int w[],int c,int i,int n){
	if(w==0 || i==n){
		return 0;
	}
	if(c<w[i]){
		return ks(cost,w,c,i+1,n);
	}
	else{
		return max(cost[i]+ks(cost,w,c-w[i],i+1,n),ks(cost,w,c,i+1,n));
	}
}
int main(){
	int cost[5]={3,4,6,7,8};
	int w[5]={2,5,3,1,6};
	cout<<ks(cost,w,10,0,5);
}
