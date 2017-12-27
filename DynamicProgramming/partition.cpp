#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		long long sum=0;
		bool flag=false;
		for(int i=0;i<n;i++){
			cin>>a[i];
			sum+=a[i];
		}
		if(sum%2)cout<<"NO"<<endl;
		else{
		sum=sum/2;	
		bool table[n+1][sum+1];
		for(int i=0;i<=n;i++)table[i][0]=1;
		for(int i=1;i<=sum;i++)table[0][i]=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=sum;j++){
				if(j>=a[i-1] && table[i-1][j-a[i-1]]){
					table[i][j]=true;
				}
				else{
					table[i][j]=table[i-1][j];
				}
			}
		}
		if(!table[n][sum])cout<<"NO"<<endl;	
		else cout<<"Yes"<<endl;
		}
		
	}
}
