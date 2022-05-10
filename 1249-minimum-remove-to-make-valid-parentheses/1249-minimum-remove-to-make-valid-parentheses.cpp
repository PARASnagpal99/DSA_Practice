class Solution {
public:
    #define pb push_back 
    string minRemoveToMakeValid(string s) {
        int n = s.length() ;
        vector<int>stk ;
        for(int i=0 ; i<n ; ++i){
            if(s[i]=='('){
                stk.pb(i);
            }else if(s[i]==')'){
                if(stk.empty()){
                    s[i] = '@' ;
                }else{
                    if(!stk.empty()){
                        stk.pop_back() ;
                    }
                }
            }
        }
        
        while(!stk.empty()){
            int x = stk.back() ;
            s[x] = '@' ;
            stk.pop_back();
        }
        
        
       string res = ""; 
       for(int i=0 ; i<n ; ++i){
           if(s[i]!='@') res.pb(s[i]);
       } 
       return res ; 
        
        
        
        
    }
};