class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size() ;
        sort(nums.begin(),nums.end());
        int cnt = 0 ;
        
        
        int left = 0 , right = n-1 ;
        while(left < right){
            cnt += (nums[right]-nums[left]);
            left++;
            right--;
        }
        
        
        
        return cnt ;
        
        
        
    }
};