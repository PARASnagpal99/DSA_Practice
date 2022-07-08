class Solution {
public:
    /*
      target = 3  , colors : 0 0 0 0 0 , if(init_target == target) ans = min(cost , ans ) 
      at every point we have n choices , we will take different choices and if its different from prev we will increment init_target . 
      
      // solving the problem in three steps : 
      
      1. 
      only if its not coloured , else if(color!=prev) init_target++;
      decide the color on the  index : func(index , prev_color , init_target)
         if(color_chosen[index] != prev_color){
              init_target++;
              cost += cost[indx][color_chosen] ;
              prev = color_chosen ;
         }
      
      2. Base case 
         if(init_target == target && index==n){
             ans = min(ans,cost) ;
         }
         
      3. make all choices at every point , we have n choices at each index :-> recursion -> overlapping subproblems -> memoization
         we will iterate over all the indices and perform this operation at each point . 
      
      1  10   if we paint with color 1 , mark color 1 in prev and increment init_target++;
      10  1   
      10  1
      1  10
      5   1
      
    */
    int dp[105][105][25] ;
    int func(int indx , int prev_color , int init_target , int target , vector<int>& houses , vector<vector<int>>& cost ){
           if(indx == houses.size() && init_target == target){
               return 0 ;
           }
           if( indx >= houses.size() or init_target > target ) return 1e6 + 5 ;
        
        if(dp[indx][init_target][prev_color]!=-1) return dp[indx][init_target][prev_color] ;
            
        int res = 1e6 + 5 ;
        if(houses[indx] != 0){
            int newInit_target = init_target ;
            if(prev_color != houses[indx]){
                newInit_target++;
            }
            res = func(indx+1,houses[indx],newInit_target,target,houses,cost) ;
        }else{
            int colors = cost[0].size() ;
            
            for(int i=1 ; i<=colors ; ++i){
                int newInit_target = init_target ;
                if(prev_color != i){
                     newInit_target++;
                }
                int curr_cost = cost[indx][i-1] + func(indx+1,i,newInit_target,target,houses,cost) ;
                res = min(res,curr_cost) ;
            }
        }
        
        return dp[indx][init_target][prev_color] = res ;
    }
    
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
         memset(dp,-1,sizeof(dp));
         int ans = func(0,0,0,target,houses,cost) ;
         if(ans == 1e6 + 5) return -1 ;
         return ans ;
    }
};