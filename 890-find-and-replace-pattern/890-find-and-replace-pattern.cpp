class Solution {
public:
    string func(string &s){
        map<char,int> mp ;
        int indx = 1 ;
        
        for(auto &it : s){
            if(mp.find(it) == mp.end()){
                mp[it] = indx ;
                indx++;
            }
            it = mp[it] ;
        }
        
        return s ;
        
    }
    
    
    
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
       vector<string> res ;
       string temp1 = func(pattern) ;
        
       for(auto &it : words){
           string temp = it ;
           string temp2 = func(it) ;
           if(temp1 == temp2) res.push_back(temp) ;
       } 
        
       return res ; 
        
    }
};