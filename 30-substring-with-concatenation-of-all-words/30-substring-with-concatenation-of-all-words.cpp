class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res ;
        int len = words[0].length() ;
        int n = s.length() ; 
        int sz = words.size() * len ;
        if(n < sz or len==0) return res ;
        
        
        
        unordered_map<string,int> mp ;
        for(auto &it : words) mp[it]++;
        
        int i = 0 ;
        while (i <= n-sz){
                int start = i  ;
                int cnt = words.size() ;
                unordered_map<string,int>count ;
                while(cnt){
                    string temp = s.substr(start,len) ;
                    count[temp]++;
                    if(mp.find(temp)!=mp.end() && mp[temp]>=count[temp]){
                        cnt--;
                        start += len ;
                    }else{
                        break ;
                    }
                }
            
            
            if(cnt==0){
                res.push_back(i) ;
            }
            
            i++;
        }
        
        return res ;
    }
};