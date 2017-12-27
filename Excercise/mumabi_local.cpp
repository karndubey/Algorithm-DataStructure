#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int h1,h2,h3,m1,m2,m3;
		char c;
		scanf("%d%c%d",&h1,&c,&m1);
		scanf("%d%c%d",&h2,&c,&m2);
		scanf("%d%c%d",&h3,&c,&m3);
		int ans= (h2*60 +m2)- (h3*60 +m3);
		printf("%d\n",ans);
	}
	
	
}
