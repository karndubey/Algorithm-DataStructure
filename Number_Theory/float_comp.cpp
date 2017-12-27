#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if(a==0)return b;
	return gcd(b%a,a);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		bool flag=false;
		int i,count=0;
		long long num=0,frac=1;
		for(i=s.length()-1;i>=0;i--){
			if(s[i]=='.'){
				flag=true;
				break;
			}
			else{
				frac*=10;
			}
		}
		if(!flag)frac=1;
		for(i=0;i<s.length();i++){
			if(s[i]!='.')
				num=num*10+(s[i]-48);
		}
		//cout<<frac<<" "<<num<<endl;
		cout<<frac/gcd(num,frac)<<endl;
	}	
}
