class Solution {
public:
    bool isValid(vector<int>& nums , int curr , int maxOperations){
        int count = 0 ;
        for(auto &it : nums){
            count += (it-1)/curr ;
        }
        return count<=maxOperations ;
    }
    
    
    
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1 , right = *max_element(nums.begin(),nums.end());
        int ans = right ;
        while(left<=right){
            int mid = (left + right) >> 1 ;
            if(isValid(nums,mid,maxOperations)){
                ans = mid ;
                right = mid-1 ;
            }else{
                left = mid+1 ;
            }
        }
       return ans ; 
    }
};