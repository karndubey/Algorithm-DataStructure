#include<bits/stdc++.h>
using namespace std;
int main(){
	long long a,b;
	cin>>a>>b;
	long long d=b-a;
	if(d>5){
		cout<<0<<endl;
	}
	else{
		long long fact=1;
		while(d--){
			fact=((fact%10)*(b%10))%10;
			b--;
		}
		cout<<fact<<endl;
	}
}
