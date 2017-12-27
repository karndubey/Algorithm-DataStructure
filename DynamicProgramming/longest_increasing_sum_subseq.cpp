#include<bits/stdc++.h>
using namespace std;
long long inc_sum_subseq(int a[],int n){
	long long sum[n];
	for(int i=0;i<n;i++)sum[i]=a[i];
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j] && sum[i]<sum[j]+a[i]){
				sum[i]=sum[j]+a[i];
			}
		}
	}
	long long max=INT_MIN;
	for(int i=0;i<n;i++){
		if(max<sum[i])max=sum[i];
	}
	return max;
}
int main(){
	int a[]={1, 101, 2, 3, 100, 4, 5};
	cout<<inc_sum_subseq(a,sizeof(a)/sizeof(a[0]));
}
