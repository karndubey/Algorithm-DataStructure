#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,p;
	scanf("%d %d %d",&n,&m,&p);
	vector<pair<int,int> > a;
	for(int i=0;i<p;i++){
		int k,l;
		scanf("%d %d",&k,&l);
		a.push_back(pair<int,int> (k,l));
	}
	sort(a.begin(),a.end());
	int j=0;
	
	for(int k=1;k<=n;k++){
		map<int,int> hash;
		int sum=m-1;
		while(j<a.size() && a[j].first==k){
				hash[a[j].second]+=1;;
				j++;
		}
		for(int i=1;i<m;i++){
			if(hash[i+1]-hash[i]<-1){
				sum=-1;
				break;
			}
			else{
				sum+=hash[i+1]-hash[i];
			//	cout<<k<<" "<<sum<<endl;
			}
		}
		cout<<sum<<endl;
	}
}
