#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
bool prime[20002],visited[10000];
int digit[10]={0,1,2,3,4,5,6,7,8,9};
void sieve(){
	for(int i=2;i*i<10000;i++){
		if(!prime[i]){
			for(int j=i*i;j<10000;j+=i){
				prime[j]=true;
			}
		}
	}
}
void make_false(){
	for(int i=0;i<10000;i++){
		visited[i]=false;
	}
}
int bfs(int l,int y){
	int u,t,h,th,temp;
	queue< pair < int, int > > q;
	q.push(make_pair(l,0));
	make_false();
	while(!q.empty()){
		int num=q.front().first;
		if(num==y){
			return q.front().second;
		}
			u=num%10;
			t=(num/10)%10;
			h=(num/100)%10;
			th=(num/1000)%10;
			//unit digit
			for(int i=1;i<=9;i++){
				temp=th*1000+h*100+t*10+digit[i];
				if(!prime[temp] && !visited[temp]){
					//cout<<temp;
					visited[temp]=true;
					q.push(make_pair(temp,q.front().second+1));
				}
			}
			//tenth place digit
			for(int i=0;i<=9;i++){
				temp=th*1000+h*100+digit[i]*10+u;
				if(!prime[temp] && !visited[temp]){
					visited[temp]=true;
					q.push(make_pair(temp,q.front().second+1));
				}
			}
			for(int i=0;i<=9;i++){
				temp=th*1000+digit[i]*100+t*10+u;
				if(!prime[temp] && !visited[temp]){
					visited[temp]=true;
					q.push(make_pair(temp,q.front().second+1));
				}
			}
			for(int i=1;i<=9;i++){
				temp=digit[i]*1000+h*100+t*10+u;
				if(!prime[temp] && !visited[temp]){
					visited[temp]=true;
					q.push(make_pair(temp,q.front().second+1));
				}
			}
			q.pop();
		}
	}
int main(){
	int t;
	sieve();
	scanf("%d",&t);
	while(t--){
		int l,h;
		scanf("%d %d",&l,&h);
		cout<<bfs(l,h)<<endl;
	}
}	
