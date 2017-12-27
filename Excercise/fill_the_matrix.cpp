#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	struct node *next;
};
int main(){
	int a[2][2];
	cout<<sizeof(int)<<" "<<sizeof(int *)<<endl;
	cout<<sizeof(a)<<" "<<sizeof(node);
}
