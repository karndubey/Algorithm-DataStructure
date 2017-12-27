#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string n,m;
		cin>>n>>m;
		bool n_neg=false,m_neg=false;
		int i=0,j=0,n_i=0,m_i=0,k,carry=0;
		if(n[0]=='-'){
			n_neg=true;
			i=1;n_i=1;
		}
		for(i;i<n.length();i++){
			if(n[i]-'0')break;
			n_i++;
		}
		if(m[0]=='-'){
			m_neg=true;
			m_i=1;
			i=1;
		}
		else i=0;
		for(i;i<m.length();i++){
			if(m[i]-'0')break;
			m_i++;
		}
		int a[n.length()-n_i],b[m.length()-m_i];
		for(i=n_i;i<n.length();i++){
			a[n.length()-1-i]=n[i]-'0';
		}
		for(i=m_i;i<m.length();i++){
			b[m.length()-1-i]=m[i]-'0';
		}
		int len=m.length()+n.length()-n_i-m_i;
		list<int> ans; vector<int> mul(len);
		for(int i=0;i<len;i++)mul[i]=0;
		
		for(i=0;i<n.length()-n_i;i++){
			k=i+1;
			carry=0;
			for(j=0;j<m.length()-m_i;j++){
				int temp= mul[len-k]+(a[i]*b[j])+carry;
				mul[len-k]=temp%10;
				//cout<<mul[len-k]<<" "<<a[i]<<" "<<b[j]<<" "<<temp<<" "<<len-k<<endl;
				carry=temp/10;
				k++;
			}
			//cout<<len-i<<" "<<mul[len-i-1]<<endl;
			ans.push_front(mul[len-i-1]);
			if(carry)mul[len-k]=carry;
		}
		len-=(n.length()-n_i+1);
		while(len>0){
			ans.push_front(mul[len]);
			len--;
		}
		if(carry)ans.push_front(carry);
		len=ans.size();
		for(i=0;i<len;i++){
			if(ans.front())break;
			ans.pop_front();
		}
		if(ans.size()){
			if(n_neg^m_neg)cout<<"-";
			for(int i=0;i<len;i++){
			cout<<ans.front();
			ans.pop_front();
		}	
		}
		else{
			cout<<0;
		}
		cout<<endl;
}
}
