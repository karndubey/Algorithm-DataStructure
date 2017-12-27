#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		int upper[26],lower[26];
		for(int i=0;i<26;i++){
			upper[i]=0;
			lower[i]=0;
		}
		for(int i=0;i<s.length();i++){
			if(s[i]=='('){
				lower[s[i-1]-'a']=1;
			}
			if(89<s[i] && s[i]<91){
				upper[s[i]-'A']=1;
			}
			if(96<s[i] && s[i]<123){
				lower[i]=1;
			}
		}
			
	}	
}
