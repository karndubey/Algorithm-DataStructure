#include<iostream>
using namespace std;
int possible_path(int n,int m){
	if(n==1 && m==1)return 1;
	else if(n==1){
		return possible_path(n,m-1);
	}
	else if(m==1){
		return possible_path(n-1,m);
	}
	else{
		return possible_path(n-1,m)+possible_path(n,m-1);
	}
}
int main(){
	cout<<possible_path(2,2);
}
