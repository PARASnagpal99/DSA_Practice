class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        int ans = 0 ;
        vector<int> suffx(n) ;
        int mx = 0 ;
        for(int i=n-1 ; i>=0 ; i--){
            mx = max(mx,height[i]);
            suffx[i] = mx ;
        }
        
        
        vector<int> prefx(n) ;
        mx = 0 ;
         for(int i=0 ; i<n ; i++){
            mx = max(mx,height[i]);
            prefx[i] = mx ;
        }
        
        for(int i=0 ; i<n ; ++i){
           int level = min(prefx[i],suffx[i]);
           if(level>=height[i]) ans+= (level-height[i]) ;
        }
        return ans ;
    }
};