class Solution {
public:
    #define pb push_back
    string removeDuplicates(string s) {
        string res = "" ;
        for(auto &it : s){
            if(res.back()!=it or res.empty()){
                res.pb(it);
            }else{
                res.pop_back();
            }
        }
        
        return res ;
    }
};