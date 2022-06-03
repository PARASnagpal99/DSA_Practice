class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() ;
        stack<int> stk ;
        map<int,int>mp ;
        vector<int> nge(n,-1);
        
        for(auto &it : nums2){
            
            while(!stk.empty() && stk.top()<it){
                mp[stk.top()] = it ;
                stk.pop() ;
            }
            
            stk.push(it) ;
        }
        
        
        for(int i=0 ; i<n ; ++i){
            if(mp.find(nums1[i])!=mp.end()){
                nge[i] = mp[nums1[i]];
            }
        }
        
        return nge ;
        
    }
};