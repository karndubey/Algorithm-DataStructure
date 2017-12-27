#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string a,b,w=""; 
		cin>>a>>b;
		int no_a[26],no_b[26];
		for(int i=0;i<26;i++){
			no_a[i]=0;
			no_b[i]=0;
		}
		for(int i=0;i<a.length();i++){
			no_a[a[i]-'a']+=1;
		}
		for(int i=0;i<b.length();i++){
			no_b[b[i]-'a']+=1;
		}
		
	}
}
