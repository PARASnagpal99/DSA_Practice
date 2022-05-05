class Solution {
public:
    #define ll long long 
    bool dfs(vector<int>&nums , vector<int>&visited , int indx , int k , int currSum , int targetSum ){
         if(k==1) return true ;
         if(indx>=nums.size()) return false ;
         if(currSum==targetSum) return dfs(nums,visited,0,k-1,0,targetSum);
         if(currSum>targetSum) return false ;
         for(int i=indx ; i < nums.size() ; ++i){
             if(!visited[i]  && targetSum >= currSum + nums[i]){
                 visited[i] = true ;   
                 if(dfs(nums,visited,i+1,k,currSum+nums[i],targetSum)) return true ;
                 visited[i] = false ; 
             }
         }
        return false ;
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size() ;        
        vector<int> visited(n,0);
        ll sum = 0 ;
        for(auto &it : nums) sum+=it ;
        if(sum%k or k>n ) return false ;
        int targetSum = sum/k ;
        sort(nums.rbegin(),nums.rend());
        return dfs(nums,visited,0,k,0,targetSum);
    }
};