class Solution {
public:
    #define pb push_back
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int>even,odd ;
        for(int i=0 ; i<n ; ++i){
            if(nums[i]&1){
                odd.pb(nums[i]);
            }else{
                even.pb(nums[i]);
            }
        }
        for(int i=0 ; i<even.size() ; ++i){
            nums[i] = even[i] ;
        }
        int k = 0 ;
        for(int i=even.size() ; i<n ; ++i){
            nums[i] = odd[k];
            k++;
        }
        return nums ;
    }
};