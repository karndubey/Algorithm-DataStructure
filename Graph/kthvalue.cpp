#include<bits/stdc++.h>
using namespace std;
  bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
    {
    	if(a.second==b.second)return (a.first<b.first);
    return (a.second > b.second);
    }
    
class Graph{
    int v;
    list<pair<int,int> > *adj;
    public:
    Graph(int vet){
        v=vet;
        adj= new list<pair<int,int> >[v+1];
    }
    void addEdge(pair<int,int> u,pair<int,int> v){
        adj[u.first].push_back(v);
        adj[v.first].push_back(u);
    }
  	void kthvalue(int u,int k){
        vector<pair<int,int> > q;
        list<pair<int,int> > :: iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++){
            q.push_back(*it);
        }
        if(k>q.size())cout<<"-1"<<endl;
        else{
            sort(q.begin(),q.end(),sortbysec);
            for(int i=0;i<q.size();i++){
            	cout<<q[i].first<<" "<<q[i].second<<endl;
            }
        cout<<q[k-1].first<<endl;
        }
        
    }
};
int main(){
    int n,m,k,u,v;
    cin>>n>>m>>k;
    Graph g(n);
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>u>>v;
        g.addEdge(make_pair(u,a[u-1]),make_pair(v,a[v-1]));
    }
    for(int i=0;i<n;i++){
        g.kthvalue(i+1,k);
    }
}
