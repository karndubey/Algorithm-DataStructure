#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,t=INT_MIN;
	scanf("%d",&n);
	pair<int,int> a[n];
	for(int i=0;i<n;i++){
		scanf("%d %d",&(a[i].first),(&a[i].second));
		if(t<a[i].second)t=a[i].second;
	}
	sort(a,a+n);
	long long k=a[n-1].first,j=0,ans=0,max;
	int sum[t+1];
	for(int i=0;i<=t;i++)sum[i]=0;
	for(int i=n-1;i>=0;i--){
		if(!sum[a[i].second])
			sum[a[i].second]=a[i].first;
		
		else{
			int j=a[i].second;
			while(j>0){
				if(!sum[j]){
					sum[j]=a[i].first;
					break;
				}
				j--;
			}
		}
	}
	for(int i=1;i<=t;i++){
	//	cout<<sum[i]<<" ";
		ans+=sum[i];
	}
	cout<<ans<<endl;
}
