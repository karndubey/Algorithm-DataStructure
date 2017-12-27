#include<bits/stdc++.h>
using namespace std;

bool issubarray(int arr1[],int arr2[],int n1,int n2){
	//size of array can be 10^5
	bool ispart[100001];
	for(int i=0;i<100001;i++)ispart[i]=false;
	for(int j=0;j<n1;j++){
		ispart[arr1[j]]=true;
	}
	int j=0;
	for(j=0;j<n2;j++){
		if(!ispart[arr2[j]])return false;
	}

	return true;
}

int main(){
	int  arr1[] = {11, 1, 13, 21, 3, 7}, arr2[] = {11, 22, 7, 1};
	cout<<issubarray(arr1,arr2,sizeof(arr1)/sizeof(arr1[0]),sizeof(arr2)/sizeof(arr2[0]));
}
