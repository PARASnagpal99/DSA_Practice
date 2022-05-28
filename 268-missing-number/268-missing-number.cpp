class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int res = nums.size() ;    // isse saare number 2 2 baar aajayenge except the one that is missing 
      for(int i=0 ; i<nums.size() ; i++){
          res = res^i ;
          res = res^nums[i];
      }
        return res ;
    }
    /*
    for example 0 1 2 4
    4 ^ 4 = 0
    2 ^ 2 = 0 
    1 ^ 1 = 0 
    bachega sirf 3 jo ki ek baar aayga 
    we take size as the start because thats not present in index .
    
    
    
    */
};
  // sort( nums.begin(), nums.end());
  //       int ans = -1 ;
  //       for(int i=0 ; i<nums.size() ; i++){
  //           if(nums[i]!=i){
  //               ans = i ;
  //               break ;
  //           }
  //       }
  //       if(ans==-1){
  //           ans = nums.size();
  //       }
  //       return ans ;