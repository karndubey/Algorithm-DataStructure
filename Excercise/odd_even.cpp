#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int i=0,j=s.length()-1,index=s.length()-1;
	for(i=0;i<s.length();i++){
		if((s[i]-'0')%2==0){
			if(s[i]<s[j]){
				index=i;
				break;
			}
			if(s[i]>s[j]){
				index=i;
			}
		}
	}
	swap(s[j],s[index]);
	cout<<s<<endl;
}
