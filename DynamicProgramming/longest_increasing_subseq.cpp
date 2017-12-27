#include<bits/stdc++.h>
using namespace std;
int longestincreasingsubseq(int a[],int i,int n){
	int lis[n];
	for(int i=0;i<n;i++)lis[i]=1;
	for(int i=1;i<n;i++){
		/*
			iterating through 0 to i-1 and storing result of max number such that a[j] > a[i]
		*/
		for(int j=0;j<i;j++){
			if(a[i]>a[j] && lis[i]<lis[j]+1){
				lis[i]=lis[j]+1;
			}
		}
	}
	int max=INT_MIN;
	for(int i=0;i<n;i++){
		if(max<lis[i])max=lis[i];
	}
	return max;
}
int main(){
	int arr[] = {1,2,3,4,5,6,7};
	cout<<longestincreasingsubseq(arr,0,sizeof(arr)/sizeof(arr[0]));
}
