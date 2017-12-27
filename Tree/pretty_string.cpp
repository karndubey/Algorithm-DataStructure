#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,count=0,max=INT_MIN;
	cin>>t;
	string s;
	cin>>s;
	bool alpha[26]={0};
	bool flag=false;
	for(int i=0;i<t;i++){
		int temp=s[i]-'a';
		if(temp>=0 && !alpha[temp]){
			flag=false;
			alpha[temp]=true;
			count++;
		}
		if(temp<0){
			if(!flag){
				for(int i=0;i<26;i++)alpha[i]=false;
				flag=true;
			}
			count=0;
		}
		if(max<count)max=count;
	}
	cout<<max;
}
