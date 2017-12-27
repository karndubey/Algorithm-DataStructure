#include<stdio.h>
struct item
{
  int weight;
  int profit;
};
void backTrack(int m,int n, int v[][n],struct item *it)
{
  int i=m-1,j=n-1;
  while(i>=0 && j>=0)
 {
  if(v[i][j] == v[i][j-1])
    j=j-1;
  else
    {
      printf("Item %d having profit %d and weight %d\n",j+1,it[j].profit,it[j].weight);
      i-=it[j].weight;
      j=j-1;
     }
  }
}
int main()
{
  // no. of items
  int n,profit=0;
  scanf("%d",&n);
  struct item it[n];
  for(int i=0;i<n;i++)
   {
     scanf("%d %d",&it[i].weight, &it[i].profit);
     profit+=it[i].profit;
   }
  int wt;
  scanf("%d",&wt);
  // v[i][j] is the  min size knapsack required for making atleast i profit with j items
  int V[p+1][n];
  for(int i=0;i<p+1;i++)
    {
     for(int j=0;j<n;j++)
      {
       V[i][j]=0;
       if(j==0 && i<=it[j].profit)
        V[i][j] = it[j].weight;
       
       if(j!=0)
      {
       V[i][j] = V[i][j-1];
       if(i>=it[j].profit && V[i][j] > it[j].weight + V[i-it[j].profit][j-1])
           V[i][j] = it[j].weight + V[i-it[j].profit][j-1];
         }
       
       }
    }
   /*for(int i=0;i<wt+1;i++)
    {
     for(int j=0;j<n;j++)
      {
        printf("%d ", V[i][j]);
       }
      printf("\n");
     }*/
   int j=p;
   while(V[][])
   printf("Profit = %d\n", V[wt][n-1]);
   backTrack(wt+1,n,V,it);
}
