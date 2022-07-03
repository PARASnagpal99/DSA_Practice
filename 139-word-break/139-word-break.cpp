class Solution {
public:
    vector<int> dp = vector<int>(305,-1) ;
    
    
    bool func(int indx , string &s ,   unordered_set<string> &st ){
        
        if(indx == s.size()){
            return true ;
        }
        
        if(dp[indx]!=-1) return dp[indx] ;
        
        string temp ;
        for(int i=indx ; i<s.size() ; ++i){
             temp.push_back(s[i]) ;
             if(st.find(temp) != st.end()){
                 if(func(i+1,s,st)) return true ;
             }
             
        }
       return dp[indx] = false ;
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st ;
        for(auto &it : wordDict){
            st.insert(it) ;
        }
        
        bool ans = func(0,s,st);
        return ans ;
        
    }
};
/*
    
    1. insert words of dict in unordered set for checking in constant time .
    2. make a recurrence relation , 
       if(check(func(i))){  // checking substring upto indx i 
         if(func(i+1)) return true 
       }
    3. memoize karo due to overlapping subproblems .
    
    
    */