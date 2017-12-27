#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int i,j,min=INT_MAX,index;
		int a[n],p[n],s[n];
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			if(i!=0){
				p[i]=p[i-1]+a[i];
			}
			else{
				p[i]=a[i];
			}
		}
		for(i=0;i<n;i++){
			if(i!=0){
				s[i]=p[n-1]-p[i-1];
			}
			else{
				s[i]=p[n-1];
			}
			if(min > s[i]+p[i]){
				min=s[i]+p[i];
				index=i+1;
			}
			
		}
		printf("%d\n",index);
	}
}
