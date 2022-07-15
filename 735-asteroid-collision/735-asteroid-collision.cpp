class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> stk ;
        
        for(auto &it : nums){
            if(it > 0){
                stk.push_back(it);
            }else{
                if(!stk.empty() && stk.back() > 0){
                    while(!stk.empty() && stk.back() > 0 && stk.back() < abs(it)){
                         stk.pop_back() ;
                    }
                    
                    if(stk.empty() or stk.back() < 0) stk.push_back(it);
                    if(!stk.empty() && stk.back() == abs(it)) stk.pop_back();
                  
                }else{
                    stk.push_back(it);
                }
            }
        }
        
        return stk ;
        
    }
};