#include<bits/stdc++.h>
using namespace std;
long long int m=1000000007;
long long int pow(int n){
	long long int m=1000000007,y=1,a=3;
	while(n>0){
		if(n%2){
			y=((y%m)*(a%m))%m;
		}
		a=((a%m)*(a%m))%m;
		n/=2;
	}
	return y;
}
int main(){
	int q;
	scanf("%d",&q);
	while(q--){
		int n;
		scanf("%d",&n);
		long long int ans=pow(n);
		cout<<ans<<endl;
		ans--;
		ans/=2;
		ans=((ans%m)*4)%m;
		ans=(ans+1)%m;
		cout<<ans<<endl;
	}
}
