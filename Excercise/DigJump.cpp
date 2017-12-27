#include<bits/stdc++.h>
using namespace std;
list<int> *graph;
bool visited[10];
void make_graph(string s){
	graph= new list<int>[10];
	//graph[0].push_back[1];
	for(int i=0;i<s.length();i++){
		if(!visited[s[i]-48]){
			graph[s[i]-48].push_back(i);
			visited[s[i]-48]=1;
		}
	}
}
int main(){
	string s;
	cin>>s;
	make_gragh(s);
}
