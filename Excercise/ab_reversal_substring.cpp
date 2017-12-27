#include<bits/stdc++.h>
using namespace std;
#define mfor(i,n) for(int i=0;i<n;i++)
#define LL long long
#define vi vector<int>
#define pb push_back
#define myfor(i,a,b) for(i=a;i<=b;i++)
#define IS_ODD( num )   ((num) & 1)
#define IS_EVEN( num )  (!IS_ODD( (num) ))
#define mod %
int compare (const void * a, const void * b)
{
  
   return *(int*)a-*(int*)b;
}
  
/*-----------------------------------------------*/
  
void maxSwap(string s) {
 if(s.length() == 0)
  return;
 //dynamic programming algorithm
 //This matrix records if the substring of s[j]....s[i] should be reversed or not
  
 vector<vector<bool> > goodSwap(s.length(), vector<bool>(s.length(), false));
 string minStr = s;//records the smallest string we can achieve
 int start = 0;
 int end = s.length() - 1;
  
  
 for(int i = 0; i < s.length(); i++) {
  for(int j = 0; j <= i; j++) {
    
   bool good;
   if(i - j < 2)
    good = true;//if i == j or i = j + 1, always good to reverse
   else {
    if(s[j] == 'b' && s[i] == 'a')//always good to reverse
     good = true;
    else if (s[j] == 'a' && s[i] == 'b')//always bad to reverse
     good = false;
    else// if (s[i] == s[j]), depends on the reversability of s[j + 1]....s[i - 1] 
     good = goodSwap[i - 1][j + 1];
   }
   if(good = true){//if it is good to reverse
    goodSwap[i][j] = true;
    string newStr = s;
    reverse(newStr.begin() + j, newStr.begin() + i + 1);//reverse the string
    if(newStr <= minStr){//if the reversed string is smaller
     start = j;
     end = i;
     minStr = newStr;//records the smallest string we can achieve
    }
   }
  }
 }
  for(int i=0;i<s.length();i++){
  	for(int j=0;j<s.length();j++){
  		cout<<goodSwap[i][j]<<" ";
  	}
  	cout<<endl;
  }
 if(start==end)
    cout<<"0"<<"  -  "<<"0"<<endl;
 else
 cout << start <<"  -  "<< end << endl;
}
int main()
{
 maxSwap("abab");
 maxSwap("abba");
 maxSwap("bbaa"); 
 maxSwap("aaaa"); 
 maxSwap("baba"); 
 return 0;
}

