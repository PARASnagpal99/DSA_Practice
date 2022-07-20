class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int n = s.length() ;
        
        vector<vector<int>>mp(26) ;
        
        for(int i=0 ; i<n ; ++i){
            mp[s[i]-'a'].push_back(i) ;
        }
        
        int cnt = 0 ;
        
       
        
        
        for(auto &it : words){
            int last = -1 ;
            bool flag = true ;
            
            for(auto &ch : it){
                auto indx = upper_bound(mp[ch-'a'].begin(),mp[ch-'a'].end(),last)  ;
                
                if(indx == mp[ch-'a'].end()){
                    flag = false ;
                    break ;
                }else{
                    last = *indx ;
                }
            }
            
            if(flag) cnt++;
        }
        
        
        
        
        return cnt ;
        
        
    }
};