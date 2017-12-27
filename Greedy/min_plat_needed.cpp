#include<bits/stdc++.h>
using namespace std;
int min_num_platform(int arr[],int dept[],int n){
	int i=1,j=0,plat_needed=1,result=1;
	while(i<n && j<n){
		if(arr[i]<dept[j]){
			plat_needed++;
			i++;
			if(result<plat_needed)result=plat_needed;
		}
		else{
			plat_needed--;
			j++;
		}
		
	}
	cout<<endl;
	return result;
}


int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int arr[n],dept[n];
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&dept[i]);
		}
		sort(arr,arr+n);
		sort(dept,dept+n);
		cout<<min_num_platform(arr,dept,n)<<endl;
	}
}
