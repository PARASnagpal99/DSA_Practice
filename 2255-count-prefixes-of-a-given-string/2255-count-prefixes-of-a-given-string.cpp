class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        map<string,int>mp ;
        for(int i=0 ; i<words.size() ; ++i){
            mp[words[i]]++;
        }
        string str = "" ;
        int ans = 0 ;
        for(int i=0 ; i<s.length() ; ++i){
            str+=s[i];
            if(mp.count(str)){
                ans+=mp[str];
            }
        }
        return ans ;
    }
};