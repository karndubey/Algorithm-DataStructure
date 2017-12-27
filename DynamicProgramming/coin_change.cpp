#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k;
	/* n= no of types of coin 
	   k= value to make from available coins
	   let k=4
	*/
	cin>>n;
	int coin[n];
	for(int i=0;i<n;i++)cin>>coin[i];
	cin>>k;
	// 2D array for building in bottom up manner
	int ways[n+1][k+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=k;j++){
			ways[i][j]=0;
		}
	}
	//if no coins are available then 0 ways to make k
	for(int i=0;i<n;i++)ways[0][i]=0;
	
	//if k=0 only 1 way to produce k i.e {} no value in set
	for(int i=0;i<=n;i++)ways[i][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			// if value of coin is greater than k say coin is five
			if(j<coin[i-1]){
			//	cout<<ways[i][j]<<" "<<ways[i-1][j]<<endl;
				ways[i][j]=ways[i-1][j];
			}
			else if(j>=coin[i-1]){
				/* if coin is less than or equal to k
				*/
				//	cout<<ways[i][j]<<" "<<ways[i-1][j]<<" "<<ways[i][j-coin[i-1]]<<endl;
				ways[i][j]=ways[i-1][j]+ways[i][j-coin[i-1]];
			}
		}
		
	}
	cout<<ways[n][k]<<endl;
}
