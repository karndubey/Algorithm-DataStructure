#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,i,budget;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	cin>>budget;
	sort(a,a+n);
	int count=0;
	for(i=0;i<n;i++){
		count=0;
		int sum=a[i];
		count++;
		for(int j=i+1;j<n;j++){
			sum+=a[j];
			for(int k=0;k<n;k++){
				if(k==i)continue;
				else{
					sum+=a[k];
					count++;
					if()
					if(sum==budget){
						break;
					}
					if(budget-sum<a[k])break;
				}
			}
		}
	}
}
