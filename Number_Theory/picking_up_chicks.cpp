#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,index=1;
	cin>>t;
	while(t--){
		long long n,k,b,T;
		cin>>n>>k>>b>>T;
		long long pos[n],v[n];
		bool reachable[n];
		for(int i=0;i<n;i++){
			cin>>pos[i];
		}
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<n;i++){
			if(pos[i]+v[i]*T>=b){
				reachable[i]=true;
			}
			else reachable[i]=false;
		}
		int finisher=0,swaps=0,temp=0;
		for(long long i=n-1;i>=0;i--){
			if(reachable[i]){
					swaps+=temp;
					finisher++;
			}
			else{
				temp++;
			}
			if(finisher==k){
				break;
			}
		}
		if(finisher>=k){
			cout<<"Case #"<<index<<":"<<" "<<swaps<<endl; 
		}
		else{
			cout<<"Case #"<<index<<":"<<" IMPOSSIBLE"<<endl;
		}
		index++;
	}
	
}
