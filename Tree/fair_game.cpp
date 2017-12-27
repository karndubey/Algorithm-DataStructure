#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int c=0,b=0,count1=1,count2=0;
	c=a[0];
	for(int i=1;i<n;i++){
		
		if(c==a[i]){
			count1++;
		}
		else if(c!=a[i] && b==0){
			b=a[i];
			count2++;
		}
		else if(b==a[i]){
			count2++;
		}
		else{
			break;
		}
	}
	if(count1==count2 && count1+count2==n){
		cout<<"YES"<<endl;
		cout<<c<<" "<<b;
	}
	else{
		cout<<"NO";
	}
}
