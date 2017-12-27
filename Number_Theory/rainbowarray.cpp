#include<bits/stdc++.h>

using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		bool flag=false;
		scanf("%d",&n);
		int a[n],order[8];
		int i=0,j=n-1,k=1;
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=0;i<=8;i++){
			order[i]=0;
		}
		while( k<=7 && i<=j){
			for(int m=1;m<=7;m++){
				if((a[i]<m && order[m]!=0) || (a[i]>m && order[m]==0)){
					flag=true;
					break;
				}
				
			}
			if(a[i]==a[j] && a[i]==k){
				while(a[i]==a[j] && a[i]==k){
				i++;
				j--;
				}
				order[a[i-1]]=1;
			}
			else{
				flag=true;
				break;
			}
			k++;
		}
			if(flag || i<=j || k<=7)printf("no\n");
			else printf("yes\n");	
	}
}
