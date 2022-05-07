class Solution {
public:
    bool find132pattern(vector<int>& nums) {
          int n = nums.size() ;
          int third_element = INT_MIN ;
          stack<int>stk ;
          for(int i=n-1 ; i>=0 ; --i){
              if(nums[i]<third_element) return true ;
              else while(!stk.empty() && nums[i]>stk.top()){
                  third_element = stk.top();
                  stk.pop() ;
              }
                  stk.push(nums[i]);
             
          }
        return false ;
    }
};