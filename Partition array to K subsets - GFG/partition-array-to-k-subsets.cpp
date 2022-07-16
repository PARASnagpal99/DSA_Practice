// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
   int dp[1 << 12][12] ;
   bool func(vector<int> &nums ,  int curr_sum , int target , int k , int mask){
       int n = nums.size() ;
       if(k == 1) return 1 ;
       
       if(dp[mask][k]!=-1) return dp[mask][k] ;
       
       if(curr_sum == target){
           return dp[mask][k] = func(nums,0,target,k-1,mask);
       }
       
       for(int i=0 ; i<n ; ++i){
           if((mask & (1 << i)) or curr_sum + nums[i] > target ) continue ;
           
           if(func(nums,curr_sum + nums[i] , target , k , mask | 1 << i)){
               return dp[mask][k] = 1 ;
           }
           
       }
       
       return dp[mask][k] = 0 ;
   }
  
  
  
  
  
  
  
  
    bool isKPartitionPossible(int arr[], int n, int k)
    {
         int sum = 0 ;
         for(int i=0 ; i<n ; ++i){
             sum += arr[i] ;
         }
         
         if(sum % k or n < k ) return 0 ;
         
         int target = sum/k ;
         memset(dp,-1,sizeof(dp));
         vector<int> nums(n) ;
         for(int i=0 ; i<n ; ++i){
             nums[i] = arr[i] ;
         }
         bool ans = func(nums,0,target,k,0);
         return ans ;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends