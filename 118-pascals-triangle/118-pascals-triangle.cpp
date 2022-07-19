class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res ;
        res.push_back({1});
        if(numRows == 1){
            return res ;
        }
        res.push_back({1,1});
        
        if(numRows == 2){
            return res ;
        }
        
        int n = numRows - 2 ;
        int sz = 3 ;
        
        while(n--){
            vector<int> temp ;
            temp.push_back(1);
            
            for(int i=1 ; i<sz-1 ; ++i){
                int prev = res[sz-2][i-1] + res[sz-2][i] ;
                temp.push_back(prev) ;
            }
            
            temp.push_back(1) ;
            res.push_back(temp) ;
            sz++;
        }
        
        
        return res ;
        
    }
};