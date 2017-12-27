#include <bits/stdc++.h>
using namespace std;
/*
	
*/
int main()
{
    long long t,n,mod=1000000007;
    scanf("%ld %ld",&t,&n);
    while(t--){
        long long cur,k;
        cin>>cur>>k;
        cout<<cur<<" "<<k<<endl;
        int a[3]={2,5,k};
        long long sum[4][cur+1];
        for(int i=0;i<=3;i++){
            for(long long j=0;j<=cur;j++){
            	cout<<i<<j<<endl;;
                if(i==0||j==0){
                    sum[i][j]=0;
                }
                else{
                    if(j<a[i-1]){
                        sum[i][j]=sum[i-1][j];
                    }
                    else{
                       
                    }
                }
            }
        }
        for(int i=0;i<=3;i++){
            for(long long j=0;j<=cur;j++){
                cout<<sum[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<sum[4][cur]<<endl;
    }
    return 0;
}

