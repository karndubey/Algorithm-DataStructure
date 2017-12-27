#include<bits/stdc++.h>
using namespace std;
struct job{
	int start,finish,profit;
};
bool jobcompare(struct job j1, struct job j2){
	return j1.finish<j2.finish;
}
int latestNonConflict(struct job jobs[],int i){
	// Initialize 'lo' and 'hi' for Binary Search
    int lo = 0, hi = i - 1;
 
    // Perform binary Search iteratively
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (jobs[mid].finish <= jobs[i].start)
        {
            if (jobs[mid + 1].finish <= jobs[i].start)
                lo = mid + 1;
            else
                return mid;
        }
        else
            hi = mid - 1;
    }
 
    return -1;
}
int maxProfit(struct job a[],int n){
	sort(a,a+n,jobcompare);
	int p[n];
	p[0]=a[0].profit;
	for(int i=1;i<n;i++){
		int inclProf=a[i].profit;
		int l=latestNonConflict(a,i);
		if(l!=-1)
		inclProf+=a[l].profit;
		p[i]=max(p[i-1],inclProf);
	}
	return p[n-1];
}
int main(){
	struct job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "The optimal profit is " << maxProfit(arr, n);
    return 0;
}
