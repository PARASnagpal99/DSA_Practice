/**
 * @param {number[]} arr
 * @return {number}
 */
var peakIndexInMountainArray = function(nums) {
     let left = 0 
     let right = nums.length - 1 
     while(left<=right){
         let mid = Math.floor(left + (right-left)/2)
         if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
             return mid 
         }else if(nums[mid]<nums[mid+1]){
             left = mid+1 
         }else if(nums[mid]<nums[mid-1]){
             right = mid-1 
         }
     }
    return left 
};