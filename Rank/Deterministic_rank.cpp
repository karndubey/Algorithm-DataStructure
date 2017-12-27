#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[]={9,8,7,6,5,4,3,2,1};
	int l=8,start=0,k=0,n=14;
	while(l>1){
		k=0;
		start=0;
		while(start<l){
		if(l-start>5){
			sort(a+start,a+start+5);
			//cout<<k<<" "<<start+2<<endl;
			swap(a[k++],a[start+2]);
		}
		else{
			sort(a+start,a+l);
			//cout<<k<<" "<<(l+start)/2<<endl;
			swap(a[k++],a[(l+start)/2]);
		}
		start+=5;
	}
	l=k;
	}
//	for(int i=0;i<)
	cout<<a[0];
}
