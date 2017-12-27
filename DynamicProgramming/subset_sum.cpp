#include<bits/stdc++.h>
using namespace std;
bool sum[101][100001];
long long subsetsum(long long n,long long maxsum,int set[]){
	for(int i=0;i<=n;i++){
		sum[i][0]=true;
	}
	for(int i=1;i<=maxsum;i++){
		sum[0][i]=false;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=maxsum;j++){
			if(j<set[i-1]){
				sum[i][j]=sum[i-1][j];
			}
			else{
				sum[i][j]=sum[i-1][j]||sum[i-1][j-set[i-1]];
			}
		}
	}
	long long ans=0;
	for(int i=0;i<=maxsum;i++){
		if(sum[n][i]){
			ans+=i;
		}
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n,maxsum=0;
		scanf("%lld",&n);
		int set[n];
		for(int i=0;i<n;i++){
			cin>>set[i];
			maxsum+=set[i];
		}
		cout<<subsetsum(n,maxsum,set)<<endl;
	}
}
