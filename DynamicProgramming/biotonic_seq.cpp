#include <bits/stdc++.h>
using namespace std;
/*
	variation of longest increasing subseq
	longest subsequence that increases and then decreases
*/
int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	    }
	    //increasing sequence;
	    int inc[n],dec[n];
	    for(int i=0;i<n;i++){
	        inc[i]=1;dec[i]=0;
	    }
	    for(int i=1;i<n;i++){
	        for(int j=i-1;j>=0;j--){
	            if(a[i]>a[j]){
	                inc[i]=max(inc[i],inc[j]+1);
	            }
	        }
	    }
	    for(int i=n-2;i>=0;i--){
	        for(int j=i+1;j<n;j++){
	            if(a[i]>a[j]){
	                dec[i]=max(dec[i],dec[j]+1);
	            }
	        }
	    }
	    int max=INT_MIN;
	    for(int i=0;i<n;i++){
	        if(max<inc[i]+dec[i])max=inc[i]+dec[i];
	    }
	    cout<<max<<endl;
	}
	return 0;
}
