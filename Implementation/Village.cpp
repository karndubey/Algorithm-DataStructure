#include<bits/stdc++.h>
using namespace std;



int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
	cin>>s;
	int count=0,ansa=0,ansb=0;
	bool a=false,b=false;
	for(int i=0;i<s.length();i++){
		if(s[i]=='A' && !a){
			b=false;
			ansa++;
			count=0;
			a=true;
		}
		else if(s[i]=='A' && a){
			ansa+=(++count);
			count=0;
			b=false;
		}
		else if(s[i]=='B' && !b){
			ansb++;
			count=0;
			a=false;
			b=true;
		}
		else if(s[i]=='B' && b){
			ansb+=(++count);
			count=0;
			a=false;
		}
		else{
			count++;
		}
	}
	cout<<ansa<<" "<<ansb<<endl;	
	
		
		
	}
}
