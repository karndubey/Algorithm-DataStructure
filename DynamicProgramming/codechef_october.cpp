#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
    	string s;
    	cin>>s;
    	int n=s.length(),counta=0,countb=0;
    	for(int i=0;i<s.lengh();i++){
    		if(s[i]=='a'){
    			counta++;
    		}
    		else{
    			countb++;
    		}
    	}
    	char h,l;
    	if(counta>countb){
    		h='a';
    		l='b';
		}
    	else{
    		h='b';
    		l='a';
    	}
    }
}

