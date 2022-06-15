class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dict (bank.begin(),bank.end());
        if(dict.find(end)==dict.end()) return -1 ;
        if(start==end) return 0 ;
        
        vector<char> options ;
        options.push_back('A');
        options.push_back('C');
        options.push_back('G');
        options.push_back('T');
        
        queue<pair<string,int>>Q ;
        Q.push({start,0});
        
        while(!Q.empty()){
            pair<string,int> curr = Q.front() ;
            Q.pop();
            string word = curr.first ;
            int cnt = curr.second ;
            if(word==end) return cnt ;
            
            dict.erase(word);
            
            for(int i=0 ; i<word.size() ; ++i){
                char k = word[i] ;
                for(int j=0 ; j<4 ; ++j){
                    if(k!=options[j]){
                        word[i] = options[j];
                        if(dict.count(word)) Q.push({word,cnt+1});
                    }
                }
                word[i] = k ;
            }
            
        }
        
        return -1 ;
    }
};