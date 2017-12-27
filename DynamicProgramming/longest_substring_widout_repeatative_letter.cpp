#include <bits/stdc++.h>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    int a[26];
	    cin>>s;
	    int start=0,max=1,end=-1;
	    for(int i=0;i<26;i++)a[i]=-1;
	    for(int i=0;i<s.length();i++){
	        if(a[s[i]-97]==-1){
	            end++;
	            a[s[i]-97]=i;
	        }
	        else{
	            int t=a[s[i]-97];
	            if(abs(t-end)==1)start=end;
	            else start++;
	            a[s[i]-97]=i;
	        }
	        cout<<start<<" "<<end<<endl;
	        if(max<end-start+1)max=end-start+1;
	    }
	    cout<<max<<endl;
	}
	return 0;
}
