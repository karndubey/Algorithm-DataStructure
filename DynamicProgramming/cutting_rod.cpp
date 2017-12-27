#include<bits/stdc++.h>
using namespace std;
int main(){
	int length[]={1,2,3,4,5,6,7,8};
	int cost[]={3,5,8,9,10,17,17,20};
	int c=8; // length of rod
	int l,len;
	//l represent length of rod to be made and len all available length
	len=8;
	l=c;
	int maxcost[len+1];
	maxcost[0]=0;
	for(int i=1;i<=l;i++){
		int max_val=INT_MIN;
		for(int j=0;j<i;j++){
			// itreate from j to i and calculate max cost
			max_val=max(max_val,cost[j]+maxcost[i-j-1]);
		}
			maxcost[i]=max_val;
	}
	for(int i=0;i<=len;i++)cout<<maxcost[i]<<" ";
	cout<<endl;
	cout<<maxcost[len];
}
