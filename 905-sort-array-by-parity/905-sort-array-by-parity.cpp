class Solution {
public:
    #define pb push_back
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if(nums[i] % 2 == 0) { //first even 
                i++;
            }
            else {
                if(nums[j] % 2 != 0) { // last odd 
                    j--;
                }
                if (nums[j] % 2 == 0) {
                    swap(nums[i],nums[j]); // first odd , last even 
                    i++;
                    j--;
                }
            }
        }
        return nums ;
    }
};