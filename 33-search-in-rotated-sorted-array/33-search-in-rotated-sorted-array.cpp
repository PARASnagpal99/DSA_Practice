class Solution {
public:
   int getPivot(vector<int>&arr , int n){
        int left = 0 , right = n - 1 ;
        while(left<right){
            int mid = left + (right-left)/2 ;
            if(arr[mid]>=arr[0]){
                left = mid + 1 ;
            }else{
                right = mid ;
            }
        }
        return left ;
    }
    
    
    int binarySearch(vector<int>&arr , int left , int right , int k){
        while(left<=right){
            int mid = left + (right-left)/2 ;
            if(arr[mid]==k){
                return mid ;
            }else if(arr[mid]>k){
                right = mid - 1 ;
            }else{
                left = mid + 1 ;
            }
        }
        return -1 ;
    }
    
    int search(vector<int>& nums, int target) {
         int n = nums.size();
         int k = target ;
         int pivot = getPivot(nums,n); 
         if(k>=nums[pivot]  && k<=nums[n-1]){
             return binarySearch(nums,pivot,n-1,k);
         }else{
             return binarySearch(nums,0,pivot-1,k);
         }
    }
};