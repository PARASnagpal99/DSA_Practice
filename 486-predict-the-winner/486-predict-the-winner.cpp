class Solution {
public:
    int dp[25][25];
    int func(vector<int>& nums , int left , int right ){
        if(left > right ) return 0 ;
        if(dp[left][right]!=-1) return dp[left][right];
        
        int choice1 = nums[left] + min(func(nums,left+2,right),func(nums,left+1,right-1));
        int choice2 = nums[right] + min(func(nums,left+1,right-1),func(nums,left,right-2));
        
        return dp[left][right] = max(choice1,choice2);
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        memset(dp,-1,sizeof(dp));
        int ans = func(nums,0,n-1) ;
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(ans>=(sum-ans)){
            return true ;
        }
        return false;
    }
};