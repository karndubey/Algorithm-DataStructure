#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,d,sum=0;
		scanf("%d %d",&n,&d);
		int a[n];
		int flag[n];
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		if(sum%n==0){
			int temp=sum/n;
			int i=0;
			while(i<d){
				int j=i+d;
				int k=i;
				while(j<n){
					if(max(a[k],a[j])>temp){
						
					}
				}
			}
		}
		else{
			printf("-1\n");
		}
	}
	
}
