class Solution {
public:
    void subsetSum(vector<int>&nums , int indx , int k , int sum , vector<vector<int>> &res){
        
        if(indx == nums.size()){
            res[k].push_back(sum) ;
            return ;
        }
        subsetSum(nums,indx+1,k,sum,res) ;
        subsetSum(nums,indx+1,k+1,sum + nums[indx] , res) ;
    }
    
    
    int minimumDifference(vector<int>& nums) {
        int n = nums.size()/2 ;
        int sum = accumulate(nums.begin(),nums.end(),0) ;
        vector<int> left ;
        vector<int> right ;
        
        for(int i=0 ; i<nums.size() ; ++i){
            if(i < n){
                left.push_back(nums[i]) ;
            }else{
                right.push_back(nums[i]) ;
            }
        }
        
        vector<vector<int>> leftSS(n+1) ;
        vector<vector<int>> rightSS(n+1) ;
        
        
        subsetSum(left,0,0,0,leftSS) ;
        subsetSum(right,0,0,0,rightSS) ;
        
        for(auto &it : rightSS) {
            sort(it.begin(),it.end());
        }
        
        
        int ans = INT_MAX ;
        
        for(int i=0 ; i<=n ; ++i){
            vector<int> lt = leftSS[i] ;
            vector<int> rt = rightSS[n-i] ;
            
            for(auto &it : lt){
                
                auto itr = lower_bound(rt.begin(),rt.end(),sum/2 - it) ;
                
                if(itr!=rt.end()){
                       int ss_sum1 = it + *itr ;
                       int ss_sum2 = sum - ss_sum1 ;
                       ans = min(ans , abs(ss_sum1 - ss_sum2));
                }
                
                 if(itr!=rt.begin()){
                       itr-- ;
                       int ss_sum1 = it + *itr ;
                       int ss_sum2 = sum - ss_sum1 ;
                       ans = min(ans , abs(ss_sum1 - ss_sum2));
                }
                
            }
            
        }
        
        return ans ;
    }
};