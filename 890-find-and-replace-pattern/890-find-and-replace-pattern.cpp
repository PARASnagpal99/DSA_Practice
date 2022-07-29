class Solution {
public:
    string func(string &s){
        map<char,char> mp ;
        int indx = 97 ;
        
        for(auto &it : s){
            if(mp.find(it) == mp.end()){
                mp[it] = char(indx++);
            }
        }
        
        for(int i=0 ; i<s.length() ; ++i){
            s[i] = mp[s[i]];
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