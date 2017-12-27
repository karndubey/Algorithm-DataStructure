#include<bits/stdc++.h>
using namespace std;
//problem statement : find position of cube free number
//cube free number is a num who doesn't have any factor as cube like 9=(1,3,9) where as 16 is not (1,2,4,8)

int cube_free[1000001];
bool a[1000001];
void position(){
	
	for(int i=2;i<=1000;i++){
		int j=i*i*i;
		for(j;j<=1000000;j+=i*i*i){
			a[j]=true;
		}
	}
	int k=1;
	for(int i=1;i<=1000000;i++){
		if(!a[i]){
			cube_free[i]=k;
			k++;
		}
	}
	
}
int main(){
	position();
	int t;
	scanf("%d",&t);
	int i=1;
	while(t--){
		int n;
		cin>>n;
		cout<<"Case"<<" "<<i<<": ";
		if(!a[n]){
			cout<<cube_free[n];
		}
		else{
			cout<<"Not Cube Free";
		}
		cout<<endl;
		i++;
	}
}
