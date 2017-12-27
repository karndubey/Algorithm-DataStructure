#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		map<string,int> vis;
		string s,f;
		cin>>s>>f;
		int pos;
		for(int i=0;i<s.length();i++){
			if(s[i]=='_'){
				pos=i;
				break;
			}
		}
		int n=s.length();
		queue<pair<string,int> > q;
		q.push({s,pos});
		vis[s]=0;
		while(!q.empty()){
			string ss=q.front().first;
			int pp=q.front().second;
			int dist=vis[ss];
			q.pop();
			if(pp>0){
				swap(ss[pp],ss[pp-1]);
				if(!vis[ss]){
					vis[ss]=dist+1;
					q.push({ss,pp-1});
			}
				if(ss==f){
					cout<<dist+1<<endl;
				}
				swap(ss[pp],ss[pp-1]);
			}
			if(pp<n-1){
				swap(ss[pp],ss[pp+1]);
				if(!vis[ss]){
					if(ss==f){
						cout<<dist+1<<endl;
						break;
					}
					vis[ss]=dist+1;
					q.push({ss,pp+1});
					
				}
				swap(ss[pp],ss[pp+1]);
			}
			if(pp>1 && ss[pp]!=ss[pp-2]){
				swap(ss[pp],ss[pp-2]);
				if(!vis[ss]){
					if(ss==f){
						cout<<dist+1<<endl;
						break;
					}
					vis[ss]=dist+1;
					q.push({ss,pp-2});
				}
				swap(ss[pp],ss[pp-2]);
			}
			if(pp<n-2 && ss[pp]!=ss[pp+2]){
				swap(ss[pp],ss[pp+2]);
				if(!vis[ss]){
					if(ss==f){
						cout<<dist+1<<endl;
						break;
					}
					vis[ss]=dist+1;
					q.push({ss,pp+2});
				}
				swap(ss[pp],ss[pp-2]);
			}
		
	}
}
}
