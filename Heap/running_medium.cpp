// C++ program to find median in 
// stream of running integers

#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

// max heap to store the higher half elements 
priority_queue<int> max_heap_left;

// min heap to store the lower half elements
priority_queue<int,vector<int>,greater<int> > min_heap_right;

// function to calculate median of stream 
void calculate_median(int x)
{
	int median;
	/*  At any time we try to make heaps balanced and 
		their sizes differ by atmost 1. If heaps are 
		balanced,then we declare median as average of 
		min_heap_right.top() and max_heap_left.top()
		If heaps are unbalanced,then median is defined 
		as the top element of heap of larger size */
	
	// case1(left side heap has more elements)
	if(!max_heap_left.size()){
		max_heap_left.push(x);
		return ; 
	}	
	if (max_heap_left.size() > min_heap_right.size())
	{	if (x < max_heap_left.top())
		{
			min_heap_right.push(max_heap_left.top());
			max_heap_left.pop();
			max_heap_left.push(x);
		}
		else
			min_heap_right.push(x);
	
	}

	// case2(both heaps are balanced)
	else if (max_heap_left.size()==min_heap_right.size())
	{
		if (x < max_heap_left.top())
		{
			max_heap_left.push(x);
		}
		else
		{
			min_heap_right.push(x);
			max_heap_left.push(min_heap_right.top());
			min_heap_right.pop();
			//min_heap_right.push(x);
		}
	}
	//cout<<"x "<<x<<" max_heap "<<max_heap_left.size()<<" min_heap "<<min_heap_right.size();
}
int print(){
	if(!max_heap_left.size()) return 0;
	int median=max_heap_left.top();
	max_heap_left.pop();
	if(max_heap_left.size()<min_heap_right.size()){
		max_heap_left.push(min_heap_right.top());
		min_heap_right.pop();
	}
	return median;
}
// Driver program to test above functions
int main()
{ 
	int x,t;
	while(true){
		scanf("%d",&x);
		if(x==0)break;
		if(x==-1)cout<<print()<<endl;
		else{
			calculate_median(x);
			//cout<<max_heap_left.top()<<endl;
		}
	}
	return 0;
}

