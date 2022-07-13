class Solution {
public:
    
    int merge(vector<int> &nums , int start , int mid , int end){
        int n = nums.size() ;
        int temp[n] ;
        
        int i = start ;
        int j = mid ;
        int k = start ;
        
        int count = 0 ;
        
        while(i < mid && j <= end){
            if(nums[i] > 2*1ll*nums[j]){
                count += (mid-i) ;
                j++;
            }else{
                i++;
            }
        }
        
        i = start , j = mid , k = start ;    
        
    
        while(i < mid && j<=end ){
            
            if(nums[i] <= nums[j]){
                temp[k++] = nums[i++] ;
            }else{
                temp[k++] = nums[j++] ;
            }
            
        }
        
        while(i < mid){
            temp[k++] = nums[i++] ;
        }
        
        while(j <= end){
            temp[k++] = nums[j++] ;
        }
        
        for(int i=start ; i<=end ; ++i){
            nums[i] = temp[i] ;
        }
        
        return count ;
        
    }
    
    
    
    int func(vector<int> &nums , int start , int end){
        if(start >= end) return 0 ;
        
        int mid = start + (end-start)/2 ;
        
        int ans1 = func(nums,start,mid) ;
        int ans2 = func(nums,mid+1,end) ;
        int ans3 = merge(nums,start,mid+1,end) ;
        
        return (ans1 + ans2 + ans3) ;
        
    }
    
    
    
    int reversePairs(vector<int>& nums) {
           int n = nums.size() ;
           int ans = func(nums,0,n-1) ;
           return ans ;
    }
};