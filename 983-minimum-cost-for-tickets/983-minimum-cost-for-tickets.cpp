class Solution {
public:
    int func(int indx , vector<int>&days , vector<int>&costs , vector<int> &dp ){
        int n = days.size() ;
        if(indx >= n) return 0 ;
        
        if(dp[indx]!=-1) return dp[indx] ;
        
        int cost = INT_MAX ;
        
        cost = min(cost, costs[0] + func(upper_bound(days.begin(),days.end(),days[indx] ) - days.begin() , days , costs,dp)) ;
        cost = min(cost, costs[1] + func(upper_bound(days.begin(),days.end(),days[indx] + 6) - days.begin() , days , costs,dp)) ;     
        cost = min(cost, costs[2] + func(upper_bound(days.begin(),days.end(),days[indx] + 29) - days.begin() , days , costs,dp)) ;
        
        return dp[indx] = cost ;
    }
        
        
        
        
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size() ;
        vector<int> dp(n+1,-1);
        int ans = func(0,days,costs,dp);
        return ans ;
    }
};