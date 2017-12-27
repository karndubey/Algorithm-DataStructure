#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		bool flag=false;
		scanf("%d",&n);
		int i=0;
		for(i=1;i<=n;i+=2){
			if(n-i==2){
				flag=true;
				break;
			}
			if(i==1){
				printf("%d %d ",i+1,i);
			}
			else{
				printf(" %d %d",i+1,i);
			}
		}
		if(flag){
			if(n==3)
			printf("%d %d %d",i+1,i+2,i);
			else printf(" %d %d %d",i+1,i+2,i);
		}
		printf("\n");
	}
}
