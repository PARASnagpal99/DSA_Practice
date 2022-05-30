class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> hsh(128,0) ;
        
        for(auto &it : t) hsh[it]++;
        int cnt = t.size() ;
        int i = 0 , j = 0 , len = s.size() ;
        int min_start = 0 , min_len = INT_MAX ;
        
        while(j<len){
            if(hsh[s[j]]>0) cnt--;
            hsh[s[j]]--;
            j++;
            while(cnt==0){
                if(j-i < min_len){
                    min_start = i ;
                    min_len = j-i ;
                }
                hsh[s[i]]++;
                if(hsh[s[i]]>0)cnt++;
                i++;
            }
        }
        if(min_len!=INT_MAX){
            string res = s.substr(min_start,min_len) ;
            return res ;
        }
        return "" ;
    }
};