class Solution {
public:

        
    

    
    int numSubseq(vector<int>& nums, int target) {
         int n = nums.size();
         int mod = 1e9 + 7 ;
         vector<int> pow(n+1,1);
         for(int i=1 ; i<=n ; ++i){
            pow[i] = (pow[i-1]*2)%mod ;
        }        
        
         sort(nums.begin(),nums.end());
         long long res = 0 ;
         int left = 0 , right = n-1 ;
         
         while(left <= right){
             if(nums[left] + nums[right] > target){
                 right--;
             }else{
                 res = (res + pow[right-left])%mod ;
                 left++;
             }
         }
        
        return res ;
    }
};