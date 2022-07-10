class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       int n = nums.size() ;
       vector<vector<int>>ans ;
       
       sort(nums.begin(),nums.end()); 
       
       for(int i=0 ; i<n-2 ; ++i){
           if(i > 0 && nums[i] == nums[i-1]) continue ;
           int target = -1*nums[i] ;
           int left = i+1 , right = n-1 ;
           
           while(left < right){
               vector<int> temp ;
               int sum = nums[left] + nums[right] ;
               if(sum == target){
                   temp.push_back(nums[i]);
                   temp.push_back(nums[left]);
                   temp.push_back(nums[right]);
                   ans.push_back(temp);
                   
                   while((left < right) && nums[left] == nums[left+1])left++;
                   while((left < right) && nums[right] == nums[right-1])right--;
                   
                   left++;
                   right--;
               }
               else if(sum > target){
                   right--;
               }else{
                   left++;
               }
           }
           
       } 
        
       return ans ; 
        
        
        
    }
};