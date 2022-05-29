class Solution {
public:
    bool isValid(vector<int>& piles, int h , int k){
          int val = 0 ;
          for(auto &it : piles){
              val += ((it+k-1)/k) ;
          }
        return val<=h ;
    }
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo = 1 ;
        int hi = *max_element(piles.begin(),piles.end()) ;
        int res = hi ;
        while(lo<=hi){
            int mid = (lo + hi )/2  ;
            if(isValid(piles,h,mid)){
                res = min(res,mid) ;
                hi = mid-1 ;
            }else{
                lo = mid + 1 ;
            }
        }
        return res ;
    }
};