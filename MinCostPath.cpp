#include<stdio.h> 
#include<limits.h> 
#define R 3 
#define C 3 
  
int min(int x, int y, int z); 
  
int minCost(int cost[R][C], int m, int n) 
{ 
   if (n < 0 || m < 0) 
      return INT_MAX; 
   else if (m == 0 && n == 0) 
      return cost[m][n]; 
   else
      return cost[m][n] + min( minCost(cost, m-1, n-1), 
                               minCost(cost, m-1, n),  
                               minCost(cost, m, n-1) ); 
} 
  
int min(int x, int y, int z) 
{ 
   if (x < y) 
      return (x < z)? x : z; 
   else
      return (y < z)? y : z; 
} 
  
int main() 
{ 
   int cost[R][C] = { {1, 2, 3}, 
                      {4, 8, 2}, 
                      {1, 5, 3} }; 
   printf(" %d ", minCost(cost, 2, 2)); 
   return 0; 
} 
