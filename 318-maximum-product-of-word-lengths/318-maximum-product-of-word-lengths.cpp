class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size() ;
        vector<int> bitmask(n) ;
        for(int i=0 ; i<n ; ++i){
            for(auto &it : words[i]){
                bitmask[i] = bitmask[i] | (1 << (it-'a')) ;
            }
        }
        
        int res = 0 ;
        for(int i=0 ; i<n ; ++i){
            for(int j=i+1 ; j<n ; ++j){
                if((bitmask[i] & bitmask[j] )== 0){
                    int x = words[i].size() , y = words[j].size() ;
                    res = max(x*y,res) ;
                }
            }
        }
        return res ;
    }
};