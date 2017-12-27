#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n=s.length();
		int *a[n];
		for(int i=0;i<n;i++){
			a[i]=(int *)malloc(n*sizeof(int));
		}
		//1 alphabet is a palindrome of length 1
		for(int i=0;i<n;i++){
			a[i][i]=1;
		}
		int j;
		for(int cl=2;cl<=n;cl++){
			for(int i=0;i<n-cl+1;i++){
				j=i+cl-1;
				if(s[i]==s[j] && cl==2){
					a[i][j]=2;
				}
				else if(s[i]==s[j]){
					a[i][j]=a[i+1][j-1]+2;
				}
				else{
					a[i][j]=max(a[i][j-1],a[i+1][j]);
				}				
			}
		}
	cout<<a[0][n-1];
	}
}
