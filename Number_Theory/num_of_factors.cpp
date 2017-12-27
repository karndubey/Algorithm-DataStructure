#include<bits/stdc++.h>
using namespace std;
bool check[10001];
vector<int> prime;
int len;
void sieve(){
	int j=0;
	for(int i=2;i<10001;i++){
		if(!check[i]){
			for(int j=i*i;j<10001;j+=i){
			check[j]=true;
		}
			prime.push_back(i);
		}	
	}
	prime.push_back(10003);
}
int main(){
	int n,index=0,count,max=0;
	cin>>n;
	sieve();
	int exp[prime.size()];
	int len=prime.size();
//	cout<<prime.size()<<endl;
	for(int i=0;i<len;i++)exp[i]=0;
	for(int i=n;i>1;i--){
		int k=0;
		int temp=i;
		index=0;
	//	cout<<temp<<" ";
		for(int j=prime[k];j<=temp;j=prime[++k]){
			count=0;
			while(temp%j==0){
				count++;
				temp/=j;
			}
			exp[k]+=count;
		}
		if(max<k)max=k;
	}
	for(int i=0;i<max;i++){
		if(exp[i]!=0){
			if(i!=max-1){
				cout<<prime[i]<<"^"<<exp[i]<<" * ";
			}
			else{
				cout<<prime[i]<<"^"<<exp[i];	
			}
		}
	}
}
