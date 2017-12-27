#include<bits/stdc++.h>
using namespace std;
int prime[180];
int check[32000];
void sieve(){
	for(int i=3;i<=180;i++){
		if(!check[i]){
			for(int j=i*i;j<=32000;j+=i){
				check[j]=1;
			}
		}
	}
	prime[0]=2;
	int j=1;
	for(int i=3;i<=32000;i+=2){
		if(!check[i]){
			prime[j++]=i;
		}
	}
}
int main(){
	sieve();
	long long a,b,n,temp,total=1,res=0,count=0;
	scanf("%lld %lld %lld",&a,&b,&n);
	for(long long i=a;i<=b;i++){
		temp=i;
		int k=0;
		total=1;
		for(int j=prime[k];j*j<=temp;j=prime[++k]){
			count=0;
			
			while(temp%j==0){
				count++;
				temp/=j;
			}
			total*=(count+1);
		}
		if(temp!=1){
			//cout<<temp<<endl;
			total*=2;
		}
		if(total==n)res++;
		//cout<<i<<" "<<total<<endl;
	}
	cout<<res;
}
