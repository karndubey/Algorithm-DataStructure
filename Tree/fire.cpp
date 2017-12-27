#include<bits/stdc++.h>
using namespace std;
bool comp(int i,int j){
	return i<j;
}
int main(){
	int n,dmax=INT_MIN,len=0;
	cin>>n;
	int t[n],p[n],d[n];
	for(int i=0;i<n;i++){
		cin>>t[i]>>d[i]>>p[i];
		if(dmax<d[i])dmax=d[i];
	}
	int sum[n+1][dmax+1];
	for(int i=0;i<=n;i++){
		for(int j=0;j<=dmax;j++){
			if(j==0 || i==0){
				sum[i][j]=0;
			}
			else if(j<t[i-1] || d[i-1]<=t[i-1]){
				sum[i][j]=sum[i-1][j];
			}
			else {
				if(sum[i-1][j]<p[i-1]+sum[i-1][j-t[i-1]]){
					sum[i][j]=p[i-1]+sum[i-1][j-t[i-1]];
				}
				else{
					sum[i][j]=sum[i-1][j];
				}
			}
		}
	}
	for(int i=0;i<=n;i++){
		for(int j=0;j<=dmax;j++){
			cout<<sum[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<sum[n][dmax]<<endl;
	int i=n,j=dmax;
	vector<int> v;
	while(i>0 && j>0){
		if(sum[i][j]!=sum[i-1][j]){
			v.push_back(i);
			j=j-t[i-1];
			i--;
		}
		else{
			i--;
		}
	}
	cout<<v.size()<<endl;
	//std::sort(v.begin(),v.end(),greater<int>());
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
}
