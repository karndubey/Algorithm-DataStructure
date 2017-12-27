#include<bits/stdc++.h>
using namespace std;
struct node{
	int val;
	int count;
};
int main(){

	int a[14]={1,2,2,3,4,5,6,4,4,6,3,2,2,7};
	int k=4;
	struct node elems[k-1];
	for(int i=0;i<k-1;i++){
		elems[i].val=0;elems[i].count=0;
	}
	int i=0,count=0;
	for(int i=0;i<14;i++){
		int j;
		if(count<k-1){
			for( j=0;j<=count;j++){
				if(elems[j].val==a[i]){
				   elems[j].count++;
				   cout<<a[i]<<endl;
				   break;
				}
			}
				if(j>count){
					cout<<a[i]<<endl;
					elems[i].count+=1;
					elems[i].val=a[i];
				 count++;
				}
		}
		else{
			for(j=0;j<k-1;j++){
				if(a[i]==elems[j].val){
					elems[j].count+=1;
					break;
				}
			}
			if(j=k-1){
				for(j=0;j<k-1;j++){
					if(elems[j].count>0)
					elems[j].count-=1;
					else{
						elems[j].count++;
						elems[j].val=a[i];
						for(int k=0;k<=j;k++)elems[k].count++;
						break;
					}
				}
			}
		}
	}
	for(int i=0;i<k-1;i++){
			cout<<elems[i].val<<" "<<elems[i].count<<" ";
		
	}
}
