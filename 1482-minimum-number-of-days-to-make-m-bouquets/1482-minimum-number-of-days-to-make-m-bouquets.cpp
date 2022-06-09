class Solution {
public:
    bool isPossible(vector<int>&nums , int days , int m , int k){
         int curr = 0 , count = 0 ;
         for(auto &it : nums){
             if(it <= days){
                  curr++;
             }else{
                 curr = 0 ;
             }
             if(curr==k){
                 count++;
                 curr = 0 ;
             }
             if(count>=m) return true ;
         }
         
        return count>=m ;
    }
    
    
    int minDays(vector<int>& Days, int m, int k) {
        int n = Days.size() ;
        int flowers = m*k ;
        if(flowers > n) return -1 ;
        int lo = 1 , hi = *max_element(Days.begin(),Days.end());
        int ans = INT_MAX ;
        while(lo <= hi){
            int mid = lo + (hi-lo)/2 ;
            if(isPossible(Days,mid,m,k)){
                ans = mid ;
                hi = mid-1 ;
            }else{
                lo = mid+1 ;
            }
        }    
        return ans ;
    }
};