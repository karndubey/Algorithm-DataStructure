#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,k,r,c;
		cin>>n>>m>>k;
		 bool a[n][m];
		 int  maze[2][m+1];
			for(int j=0;j<=m;j++){
				maze[0][j]=0;
			}
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++)a[i][j]=false;
			}
		for(int i=0;i<k;i++){
			cin>>r>>c;
			a[r-1][c-1]=true;
		}
		int p,t;
		for(int i=1;i<=n;i++){
			p=(i-1)%2;
			t=i%2;
			for(int j=0;j<=m;j++){
				if(j==0)maze[t][j]=0;
				else if(j==1 && i==1){
					maze[t][j]=1;
				}
				else{
					if(!a[i-1][j-1]){
						//cout<<i<<" "<<j<<endl;
						maze[t][j]=(maze[p][j]+maze[t][j-1])%1000000007;
					}
					else{
						maze[t][j]=0;
					}
				}
			}
		
	}
	cout<<maze[t][m]<<endl;
}
}
