#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int a[n/2+1];
		long long i=1,pow=1,m=n,j=0;
		while(pow<n){
			if(m%2==1){
				a[j]=pow;
				j++;
			 }
			m/=2;
			pow*=2;
		}
		long long count=0;
		if(j<=k){
			cout<<-1<<endl;
		}
		else{
		for(int i=0;i<j-k;i++){
			if(a[i]!=a[i+1]){
			if(a[i]==1){
				count+=(a[i+1]-a[i]);
			}
			else{
			  	int temp=a[i];
			  	while(temp<a[i+1]){
			  		count+=temp;
			  		temp*=2;
			  	}
				  			
			}
			a[i+1]*=2;
		}
		}
		cout<<count<<endl;	
	  }
	}
}
