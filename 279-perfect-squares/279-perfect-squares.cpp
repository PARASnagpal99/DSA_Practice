class Solution {
public:
    /*
     condition for perfect square : 
     nums 
     let x = sqrt(nums) 
     if(x * x == nums) yes its a perfect square 
     
     backtracking --> dfs 
     least number -> shortest path -> bfs , related to branch and bound 
     
     recurrence : func(n) = func(n - y) + 1  , top to bottom 
     
     for (i =1 ; i*i <=n ; ++i) y = i*i // this will do the work . 
     
     base case  : if(n==0) return 1 ; 
     
    
    */
    vector<int> dp = vector<int>(10005,-1) ;
    int numSquares(int n) {
         if(n==0) return 0 ;
         if(n<0) return INT_MAX ;
         if(dp[n]!=-1) return dp[n] ;
         int min_steps = INT_MAX ;
         for(int i=1 ; i*i <= n ; ++i){
             min_steps = min(min_steps , numSquares(n-i*i) + 1) ;
         }
        return dp[n] = min_steps  ;
    }
};