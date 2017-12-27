#include<bits/stdc++.h>
using namespace std;
int smallest_factor[100000000];
void find_smallest_prime(){
	for(int i=2;i<4000;i++){
		if(!smallest_factor[i]){
			for(int j=i;j<10000000;j+=i){
			if(!smallest_factor[j]){
			smallest_factor[j]=i;
			}	
		}	
		}
	}
}
int main(){
	find_smallest_prime();
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		cin>>n;
		long long ans=0,a=0,b=0;
		for(int i=2;i<=n;i++){
			if(smallest_factor[i]==0)smallest_factor[i]=i;
			ans=b+smallest_factor[i];
			b=ans;
		}
		cout<<ans<<endl;
	}
}
