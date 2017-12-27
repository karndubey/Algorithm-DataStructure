#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		string s;
		cin>>s;
		int a[10];
		for(int j=0;j<10;j++)a[j]=0;
		for(int i=0;i<s.length();i++){
			int temp=s[i]-'0';
			a[temp]+=1;
		}		
		char alpha[26];
		for(int i=0;i<26;i++)alpha[i]=0;
		int count=0;
		for(int i=6;i<10;i++){
			if(a[i]!=0){
				if(i==6){
					int j=5;
					while(j<10){
						if(a[j]!=0){
							if(j!=i){
							int temp= i*10 +j -65;
							alpha[temp]=1;
						    }
						    else{
						    	if(a[i]>1){
						    		int temp= i*10 +j -65;
									alpha[temp]=1;
						    	}
						    }
						}
						j++;
					}
				}
				else if(i==9){
					if(a[0]!=0){
						int temp= i*10-65;
						alpha[temp]=1;
					}
				}
				else{
					int j=0;
					while(j<10){
						if(a[j]!=0){
							if(j!=i){
							int temp= i*10 +j -65;
							alpha[temp]=1;
						    }
						    else{
						    	if(a[i]>1){
						    		int temp= i*10 +j -65;
									alpha[temp]=1;
						    	}
						    }
						}
						j++;
					}
				}
			}
			else
			count++;	
		}
		if(count<4){
		for(int i=0;i<26;i++){
			if(alpha[i]==1){
				char c=i+65;
				cout<<c;
			}
			
		}
	}
		cout<<endl;
		}
}
