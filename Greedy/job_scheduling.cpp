#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
	int n;
	scanf("%d",&n);
	pair<int, int> a[n];
	//storing end_time in first and second time in second
	for(int i=0;i<n;i++){
		scanf("%d %d",&(a[i].second),&(a[i].first));
	}
	sort(a,a+n);
	int ans=0,end_time,j,i=0;
	while(i<n){
		if(i==0){
			end_time=a[i].first;
			ans++;
			
		}
		else if(a[i].second>=end_time){
			ans++;
			
			end_time=a[i].first;
		}
			i++;
		}
	cout<<ans<<endl;
}
}
