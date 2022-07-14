class Solution {
public:
    int dp[2001][2001] ;
    
    bool func(int indx , int prev_jump , vector<int> &stones){
        int n = stones.size() ;
        if(indx == n-1) return true ;
        if(indx >= n) return false ;
        
        if(dp[indx][prev_jump]!=-1) return dp[indx][prev_jump] ;
        
        bool ans = false ;
        
        for(int j=-1 ; j<=1 ; ++j){
            int jump = prev_jump + j ;
            if(jump > 0){
                int i = lower_bound(stones.begin(),stones.end(),stones[indx]+jump) - stones.begin() ; 
                
                if(indx >= n or stones[i] != stones[indx] + jump) continue ;
                
                ans = ans || func(i,jump,stones) ;
            }
        }
        
        return dp[indx][prev_jump] = ans ;
    }
    
    
    bool canCross(vector<int>& stones) {
            memset(dp,-1,sizeof(dp));
            bool ans = func(0,0,stones) ;
            return ans ;
    }
};