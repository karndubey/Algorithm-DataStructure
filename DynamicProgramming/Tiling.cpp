#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int w;
	    cin>>w;
	    int a=1,b=1,c;
	    for(int i=2;i<=w;i++){
	        c=a+b;
	        a=b;
	        b=c;
	    }
	    cout<<c<<endl;
	}
	return 0;
}
