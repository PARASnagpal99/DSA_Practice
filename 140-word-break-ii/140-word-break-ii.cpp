class Solution {
public:
    
    void func(int indx , string &s , unordered_set<string>st , string temp , vector<string>&res ){
        if(indx == s.size()){
            temp.pop_back() ;
            res.push_back(temp) ;
        }
        
        string str = "" ;
        
        for(int i=indx ; i < s.size() ; ++i){
            str.push_back(s[i]);
            if(st.count(str)){
                 func(i+1,s,st,temp+str+" ",res);       
            }
        }
        
    }
    
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st ;
        for(auto &it : wordDict){
            st.insert(it) ;
        }
        
        string temp ;
        vector<string>res ;
        func(0,s,st,temp,res);
        return res ;
    }
};