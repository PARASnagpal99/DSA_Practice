class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        int n = messages.size() ;
        map<string,int> mp ;
        for(int i=0 ; i<n ; ++i){
            int count = 1 ;
            for(int j=0 ; j<messages[i].size() ; ++j){
                if(messages[i][j]==' ') count++;
            }
            mp[senders[i]]+=count ;
        }
        string res  ;
        int mx = 0 ;
        for(auto &it : mp){
            if(it.second>=mx){
                mx = it.second ;
                res = it.first ;
            }
        }
        return res ;
    }
};