#include<bits/stdc++.h>
using namespace std;
struct job{
	int start,finish,profit;
};
bool jobComparator(struct job j1,struct job j2){
	return j1.finish<j2.finish;
}
int latestConflict(struct job a[],int i){
	int l=0,h=i-1;
	while(l<=h){
		int mid=l+h/2;
		if(a[mid].finish<=a[i].start){
			if(a[mid+1].finish<=a[i].start)l=mid+1;
			else{
				return mid;
			}
		}
		else{
			h=mid-1;
		}		
		
	}
	return -1;
}
long long maxprofit(struct job a[],int n){
	sort(a,a+n,jobComparator);
	long long p[n];
	p[0]=a[0].profit;
	for(int i=1;i<n;i++){
		long long inclProf=a[i].profit;
		int l=latestConflict(a,i);
		if(l!=-1)
		inclProf+=a[l].profit;
		p[i]=max(inclProf,p[i-1]);
	}
	return p[n-1];
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,duration;
		scanf("%d",&n);
		struct job a[n];
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&a[i].start,&duration,&a[i].profit);
			a[i].finish=a[i].start+duration;
		}
		cout<<maxprofit(a,n)<<endl;
	}
}
