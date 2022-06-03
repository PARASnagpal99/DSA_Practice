class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        int n = nums.size() ;
        stack<int> stk ;
        vector<int> res(n,0) ;
        for(int i=0 ; i<n ; ++i){
            
            while(!stk.empty() && nums[stk.top()] < nums[i]){
                res[stk.top()] = i - stk.top() ;
                stk.pop() ;
            }
           stk.push(i) ;
        }
        
        
        return res ;
    }
};