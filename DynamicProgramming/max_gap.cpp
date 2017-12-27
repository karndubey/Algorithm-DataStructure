#include<bits/stdc++.h>
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
using namespace std;
long long int leftdp[10004][2],rightdp[10004][2];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		leftdp[0][0]=a[0];
		leftdp[0][1]=a[0];
		for(int i=1;i<n-1;i++){
			leftdp[i][0] = max(leftdp[i-1][0],0) + a[i];
	    leftdp[i][1] = min(leftdp[i-1][1],0) + a[i];
		}
		rightdp[n-1][0]=a[n-1];
		rightdp[n-1][1]=a[n-1];
		for(int i=n-2;i>=0;i--){
			rightdp[i][0]=max(rightdp[i+1][0],0)+a[i];
			rightdp[i][1]=min(rightdp[i+1][1],0)+a[i];
		}
		long long int ans=0;
		for(int i=0;i<n-1;i++){
			ans=max(ans,abs(leftdp[i][0]-rightdp[i+1][1]));
			ans=max(ans,abs(rightdp[i+1][0]-leftdp[i][1]));
		}
		cout<<ans<<endl;
	}
}
