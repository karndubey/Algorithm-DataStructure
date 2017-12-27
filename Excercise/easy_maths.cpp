#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		signed int operand[n+1];
		string op;
		cin>>op;
		for(int i=0;i<n+1;i++){
			scanf("%d",&operand[i]);
		}
		float ans=operand[0];
		for(int i=0;i<n;i++){
			if(op[i]=='+'){
				ans+=operand[i+1];
			}
			else if(op[i]=='-'){
				ans-=operand[i+1];
			}
			else if(op[i]=='*'){
				ans*=operand[i+1];
			}
			else{
				ans/=operand[i+1];
			}
		}
		cout<<ans<<endl;
	}
	
}
