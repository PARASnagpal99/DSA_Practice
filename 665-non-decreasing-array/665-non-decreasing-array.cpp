class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        int n = nums.size() ;
        
        int cnt = 0 ;
        
        for(int i=0 ; i<n-1 ; ++i){
            
            if(nums[i] > nums[i+1] && cnt < 1 ){
                cnt++;
                if(i+2!=n){
                    if(nums[i] <= nums[i+2]){
                        nums[i+1] = nums[i] ;
                    }else{
                        nums[i] = nums[i+1] ;
                    }
                }
                
                if(i+2 == n ){
                    
                    nums[i+1] = nums[i] ;
                    
                    
                    
                }    
            }
        }
        
        
        for(int i=0 ; i<n-1 ; ++i){
            if(nums[i] > nums[i+1]) return false ;
        }
        
        return true ;
        
        
        
        
        
        
    }
};