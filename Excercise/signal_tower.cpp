#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long n;
        cin>>n;
        long long a[n],h[n],ans[n],l=0,r=0;
        for(int i=0;i<n;i++){
        	cin>>a[i];
        	ans[i]=0;
    }
        h[r]=n-1;
        for(int i=n-2;i>=0;i--){
            if(a[h[r]]>=a[i]){
                h[++r]=i;
            }
            else{
                while( r>=0 && a[h[r]]<a[i]){
                    ans[h[r]]=abs(h[r]-i);
                    r--;
                }
                h[++r]=i;
            }
        }
        for(int i=0;i<n;i++){
        	if(ans[i]==0)cout<<i+1<<" ";
        	else cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

