class Solution {
public:
    /*
    1 2 2 2 5 0 
    1 3 5 7 12 12
    1 2 9
    1 4 7
    
    
    */
    int waysToSplit(vector<int>& nums) {
        int n = nums.size() ;
        int mod = 1e9 + 7 ;
        vector<int> prefx(n) ;
        prefx[0] = nums[0] ;
        for(int i=1 ; i<n ; ++i){
           prefx[i] = prefx[i-1] + nums[i] ;    
        }
      
        int cnt = 0 ;
        
        for(int i=0 ; i<n-2 ; ++i){
           auto start = lower_bound(prefx.begin()+i+1 , prefx.end() , 2*prefx[i]) ;
           auto end = upper_bound(prefx.begin()+i,prefx.end()-1 , (prefx.back()+prefx[i])/2) ;
           if(end > start){
               cnt = (cnt + end-start)%mod ;
           }
        }
        return cnt ;
    }
};