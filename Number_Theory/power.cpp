#include<bits/stdc++.h>
using namespace std;
long long pow(long long a,long long n,long long p){
	long long temp=1;
	while(n){
		if(n%2)temp=((temp%p)*(a%p))%p;
		a=((a%p)*(a%p))%p;
		n/=2;
	}
	return temp;
}
long long rem(long long a,long long A,long long n,long long p,long long i){
//	cout<<a<<" "<<i<<endl;
	if(i==n){
		return a%p;
	}
	if(!a)return a;
	long long temp=rem(((a%p)*(A))%p,A,n,p,i+1);
	if(temp==1||temp==0)return temp;
	temp=pow(temp,i,p)%p;
	return temp;
}
int main(){
	long long test,j=1;
	cin>>test;
	while(test--){
		long long a,n,p;
		cin>>a>>n>>p;
		if(a%p==0){
			cout<<"Case #"<<j<<": "<<0<<endl;
		}
		else{
			cout<<"Case #"<<j<<": "<<rem(a,a%p,n,p,1)<<endl;
		}
		j++;
	}
}
