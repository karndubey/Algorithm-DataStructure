#include<bits/stdc++.h>
using namespace std;
int main(){
 int t;
 cin>>t;
 while(t--){
 	string s;
 	cin>>s;
 	int ans=0,k=0;
 	for(int i=0;i<s.length();i++){
 		if(s[i]=='<')k++;
 		else k--;
 		if(k==0)ans=max(ans,i+1);
 		else if(k<0){
 			break;
 		}
 	}
 	cout<<ans<<endl;
}
}
