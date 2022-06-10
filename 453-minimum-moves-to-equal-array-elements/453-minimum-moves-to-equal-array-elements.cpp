class Solution {
public:
    /*
    
    1  5  7  9  15   
    15 19 21 23 15   14
    23 27 29 23 23    8
    29 33 29 29 29    6 
    33 33 33 33 33    4
               ans = 32
               
               
     let sum total be sum           
     
     after moves M 
     sum + M * (n-1) = n * x  , where x is equal element           
               
     min_num + M = x 
     
     
     sum + M * (n-1) = n * (min_num + M) 
     sum - M = n*min_num          
     M = sum - n*min_num           
               
               
               
               
    */
    int minMoves(vector<int>& nums) {
        int n = nums.size() ;    
        int sum = accumulate(nums.begin(),nums.end(),0) ;
        int min_number = *min_element(nums.begin(),nums.end());
        
        int ans = sum - n*(min_number) ;
        return ans ;
        
    }
};