class Solution {
public:
    long long func(int i , int j , vector<int>&cuts , vector<vector<long long>>&dp ){
        if(i>j) return 0 ;
        if(dp[i][j]!=-1) return dp[i][j] ;
        int min_cost = 1e9 ;
        for(int ind = i ; ind<=j ; ++ind){
            long long cost = cuts[j+1] - cuts[i-1] + func(i,ind-1,cuts,dp) + func(ind+1,j,cuts,dp) ;
            min_cost = min(min_cost*1ll,cost) ; 
        }
        return dp[i][j] = min_cost ;
    }
    
    
    int minCost(int n, vector<int>& cuts) {
         cuts.push_back(n) ;
         cuts.insert(cuts.begin(),0);
         sort(cuts.begin(),cuts.end()) ;
         int c = cuts.size() ;
         vector<vector<int>> dp(c,vector<int>(c,0));
         for(int i=c-2 ; i>=1 ; i--){
             for(int j=1 ; j<=c-2 ; j++){
                 if(i>j) continue ;
                 int min_cost = INT_MAX ;
                 for(int ind=i ; ind<=j ; ++ind){
                     int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j] ;
                     min_cost = min(min_cost,cost);
                 }
                 dp[i][j] = min_cost ;
             }
         }
        return dp[1][c-2] ;
    }
};