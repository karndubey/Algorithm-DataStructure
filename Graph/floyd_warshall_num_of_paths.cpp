#include <bits/stdc++.h>
using namespace std;
int path[1000][1000];
void print_path(int k,int j){
	if(path[k][j]==-1){
		cout<<"NO PATH"<<endl;
	}
	else if(path[k][j]==j){
		cout<<j+1<<" ";
	}
	else{
		
		print_path(k,path[k][j]);
		print_path(path[k][j],j);
	}
}
int main() {
    int t;
    cin>>t;
    while(t--){
    	cout<<INT_MAX;
        int n;
        cin>>n;
        long long a[n][n],d[n][n],N[n][n];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
                d[i][j]=a[i][j];
                if(a[i][j] && a[i][j]!=INT_MAX){
                	N[i][j]=1;
                }
                else{
                	N[i][j]=0;
                }
            }
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		if(i==j){
        			path[i][j]=j;
        		}
        		else if(a[i][j] && a[i][j]!=INT_MAX){
        			path[i][j]=j;
        		}
        		
        		else{
        			path[i][j]=-1;
        		}
        	}
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		cout<<path[i][j]<<" ";
        	}
        	cout<<endl;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<N[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int k=1;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(d[i][j]>d[i][k]+d[k][j]){
                        d[i][j]=d[i][k]+d[k][j];
                        N[i][j]=N[i][k]*N[k][j];
                        path[i][j]=k;
                    }
                    else if(d[i][j]==d[i][k]+d[k][j]){
                    	N[i][j]+=N[i][k]*N[k][j];
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<d[i][j]<<" ";
            }
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
            	if(N[i][j]>1)N[i][j];
                cout<<N[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		cout<<path[i][j]<<" ";
        	}
        	cout<<endl;
        }
        cout<<"PATH FOLLOWED"<<endl;
        int v,u;
        cin>>u>>v;
        cout<<u<<" ";
        print_path(u-1,v-1);
    }
	return 0;
}
