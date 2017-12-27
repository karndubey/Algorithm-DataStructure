#include<bits/stdc++.h>
using namespace std;

struct node{
	long long sum;
	int min;
	int l;
	int r;
};
int range(struct node a[],int i,int k,int m){
	if(k >a[i].l && m=<a[i].r){
		
	}
	if(k>a[i].l && m<a[i].r){
		return a[i].min;
	}
	else{
		return 0;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n,m,q;
		cin>>n>>m>>q;
		struct node *a= new node[2*n-1];
		int j=2*n-2;
		for(int i=0;i<n;i++){
			cin>>a[j-i].sum;
			//cout<<a[j-i].sum<<" ";
			a[j-i].l=a[j-i].r=i;
			if(a[j-i].sum>=m){
				a[j-i].min=1;
			}
			else a[j-i].min=INT_MAX;
		}
		for(int i=n-2;i>=0;i--){
			a[i].sum=a[j].sum+a[j-1].sum;
			a[i].l=std::min(a[j-1].l,a[j].l);
			a[i].r=std::max(a[j-1].r,a[j].r);
			if(a[j].sum>=m || a[j-1].sum>=m){
				a[i].min=std::min(a[j].min,a[j-1].min);
			}
			else{
				if(a[i].sum>=m)a[i].min=a[i].r-a[i].l+1;
				 else{
				 	a[i].min=INT_MAX;
				 }	
			}
			j-=2;
		}
		for(int i=0;i<2*n-1;i++){
			cout<<a[i].sum<<
		}
		while(q--){
			int k,m;
			scanf("%lld %lld",&k,&m);
			k--;m--;
			int i=0;
			i=range(i,k,m);
			if(a[i].min==INT_MAX)printf("-1\n");
			else printf("%d\n",a[i].min);
		}
	}
}
