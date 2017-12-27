#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,a;
	long long k,index=1,power=1;
	cin>>s;
	cin>>k;
	for(int i=0;i<s.length();i++){
		if(s[i]>47 && s[i]<58){
			while(s[i]>47 && s[i]<58){
				index+=(s[i]-'0')*power;
				power*=10;
			}
		}
	}
}
