class Solution {
public:
    /*
    
    2 2 3 4 
    
    2 , 2 , 3 
    2 + 2 = 4 
    2 + 3 = 5
    
    2 3 4 
    triangle sum property : a + b > c , b + c > a , a + c > b 
    
    
    
    */
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 0 ;
        int n = nums.size() ;
        for(int i=2 ; i<n ; ++i){
            int left = 0 , right = i-1 ;
            while(left<right){
                if(nums[left]+nums[right]>nums[i]){
                    cnt += (right-left) ;
                    right--;
                }else{
                    left++;
                }
            }
        }
        return cnt ;
    }
};