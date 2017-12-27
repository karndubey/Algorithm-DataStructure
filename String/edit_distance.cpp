#include<bits/stdc++.h>
using namespace std;
int editDistance(string str1, string str2 ){
	int a[2][str2.length()+1];
	int p;
	for(int i=0;i<=str1.length();i++){
		p= i&1;
		int temp= p==1 ? 0 : 1;
		for(int j=0;j<=str2.length();j++){
			if(i==0){
				a[i][j]=j;
			}
			else if(j==0){
				a[p][j]=i;
			}
			else if(str1[i-1]==str2[j-1]){
				a[p][j]=a[temp][j-1];
			
			}
			else{
				a[p][j]=1+min(a[temp][j-1],min(a[temp][j],a[p][j-1]));		
			}
		}
	}
	
	return a[p][str2.length()];
}
