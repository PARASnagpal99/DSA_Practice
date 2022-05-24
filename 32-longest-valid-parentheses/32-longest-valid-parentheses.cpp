class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length() ;
        if(!n) return 0 ;
        vector<pair<char,int>>stk ;
        stk.push_back({'#',-1});
        for(int i=0 ; i<n ; ++i){
            if(s[i]==')' && stk.back().first=='(') stk.pop_back() ;
            else stk.push_back({s[i],i});
        }
        stk.push_back({'#',n});
        int ans = 0 ;
        for(int i=0 ; i<stk.size()-1 ; ++i){
            ans = max(ans,stk[i+1].second-stk[i].second-1);
        }
        return ans ;
    }
};