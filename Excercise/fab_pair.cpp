#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    long long a[n];
     bool flag[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        flag[i]=false;
    }
    int count=0;
   
    for(int i=0;i<n-1;i++){
        int max=a[i],sec_max=0,max_i=i,sec_max_i=-1;
        
        for(int j=i+1;j<n;j++){
            if(max<a[j]){
            //	cout<<max<<" "<<max_i<<" "<<sec_max<<" "<<sec_max_i<<endl;
                sec_max=max;
                sec_max_i=max_i;
                max_i=j;
                max=a[j];
            //    cout<<max<<" "<<sec_max<<endl;
                flag[j-i]=true;
            }
            else{
            	if(sec_max>a[j]){
            		flag[j-i]=true;
            	}
            	else{
            		sec_max_i=j;
            		sec_max=a[j];
            	}
            }
        }
    }
    for(int i=0;i<n;i++){
    	if(flag[i])count++;
    }
    cout<<count<<endl;
    return 0;
}

