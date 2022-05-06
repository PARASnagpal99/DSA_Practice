class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>>stk ;
        
        for(auto &it : s){
            if(stk.size()==0 or stk.back().first!=it){
                stk.push_back({it,1});
            }else if(stk.back().first==it){
                pair<char,int>p = stk.back() ;
                stk.pop_back() ;
                stk.push_back({p.first,p.second+1});
                if(stk.back().second==k){
                    stk.pop_back() ;
                }
            }
        }
        
        string res = "" ;
        for(auto &it : stk) res.append(it.second,it.first);
        return res ;
        
    }
};