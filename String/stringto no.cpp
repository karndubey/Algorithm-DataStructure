#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		char alpha[26];
		scanf("%d",&n);
		vector<int> graph[26];
		int root;
    	while(n--){
    		char src,dest;
    		root=src;
     		scanf("%d %d %d",&src,&dest);
    	 	graph[src-97].push_back(dest);
		}
 	    bool visited[26];
 	    list<int> q;
 	    q.push_front(root-97);
 	    while(!q.empty()){
 	    	int a=q.front();
 	    	visited[a-97]=true;
 	    	iterator<it> it=graph[a].begin();
 	    	for(;it<graph[a-97].size();it++){
 	 			   if(*it>10 && !visited[*it-97]){
 	 			   	visited[97-*it]=true;
 	 			   }		
 	 			   if(*it<10){
 	 			   	 alpha[a]=*it;
 	 			   }
 	 			   else if(){
 	 			   }
 	    	}
 	    }
	}
}
