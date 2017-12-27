#include<bits/stdc++.h>
using namespace std;
bool subset(int a[],int sum,int n){
	bool set[n+1][sum+1];
	for(int i=0;i<=n;i++)set[i][0]=true;
	for(int i=0;i<=sum;i++)set[0][i]=false;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(j>=a[i-1]){
				set[i][j]=set[i-1][i-a[i-1]]||set[i-1][j];
			}
			if(j<a[i])set[i][j]=set[i-1][j];
		}
	}
	return set[sum];
}

int main(){
	int set[] = {3, 34, 4, 12, 5, 2}, sum = 9;
	cout<<subset(set,sum,6);
}
