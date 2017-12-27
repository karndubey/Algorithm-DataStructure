#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	list<char> stack; 
	for(int i=0;i<s.length();i++){
		if(!stack.empty() && stack.front()==s[i] ){
			stack.pop_front();
		}
		else{
			stack.push_front(s[i]);
		}
	}
	if(stack.size()) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
