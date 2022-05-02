class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size() ;
        int zero_ptr = 0 ;
        for(int i=0 ; i<n ; ++i){
            if(nums[i]==0){
                swap(nums[zero_ptr++],nums[i]);
            }
        }
         
        int two_ptr = n-1 ;
        for(int i=n-1 ; i>=0 ; --i){
            if(nums[i]==2){
                swap(nums[two_ptr],nums[i]);
                two_ptr--;
            }
        }

    }
};