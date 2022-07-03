class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> down(n,1) ;
        vector<int> up(n,1) ;
        
        int maxlen = 1 ;
        
        for(int i=0 ; i<n ; ++i){
            for(int prev=0 ; prev < i ; ++prev){
                if(nums[i] > nums[prev]){
                    up[i] = max(up[i],1 + down[prev]) ;
                    down[i] = down[prev] ;
                }
                
                if(nums[i] < nums[prev]){
                    down[i] = max(down[i],1+up[prev]);
                    up[i] = up[prev] ;
                }
                
            } 
            maxlen = max(down[i],up[i]);
        }
        
        return maxlen ;
        
        
        
        
    }
};