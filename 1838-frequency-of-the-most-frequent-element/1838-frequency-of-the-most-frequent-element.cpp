class Solution {
public:
    /*
    check for each element 
    logic is that first we sort the array because the nearest element to the current element  will require minimum operations to become equal 
    to count the number of elements which we can make equal to current element we maintain a window . length of this window gives the maximum possible       answer to that element 
    
    while(sum of all elements in window + k  >= nums[curr] * len of window ) curr++;
    else{
        sum-=nums[start] ;
        start++;
    }
    
    */
    int maxFrequency(vector<int>& nums, int k) {
          int n = nums.size() ;
          sort(nums.begin(),nums.end()) ;
          int ans = 0 ;
          long long start = 0 , curr = 0 ;
          long long sum = 0 ;
          while(curr < n){
              sum+=nums[curr] ;
              long long len = curr - start + 1 ;
              if(sum + k >= nums[curr] * len ){
                   ans = max(ans*1ll,len);
              }
              
              while(sum + k < nums[curr]*len){
                    sum-=nums[start] ;
                    start++;
                    len-- ;
              }
              
              curr++;
          }
        
        return ans ;
    }
};