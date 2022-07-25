class Solution {
public:
    int lower_bound(vector<int>&nums , int left , int right , int target){
        
        while(left < right){
            int mid = left + (right-left)/2 ;
            
            if(nums[mid] >= target){
                right = mid;
            }else{
                left = mid + 1 ;
            }
        }
        
        
        if(left < nums.size() && nums[left] < target) left++;
        
        return left ;
    }
    
    
    int upper_bound(vector<int>&nums , int left , int right , int target){
        
               while(left < right){
                   int mid = left + (right-left)/2 ;
                   
                   if(nums[mid] <= target){
                       left = mid + 1 ;
                   }else{
                       right = mid;
                   }
               }
        if(left < nums.size()  && nums[left] <= target){
            left++;
        }
        return left ;
    }
    
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size() ;
        
        int first = lower_bound(nums,0,n-1,target) ;
        int second = upper_bound(nums,0,n-1,target) ;
        second-- ;
        
        if(first < n && nums[first] == target){
            return {first,second} ;
        } 
        
        return {-1,-1} ;
        
        
    }
};