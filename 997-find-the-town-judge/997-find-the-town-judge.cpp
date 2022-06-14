class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        if(trust.empty() && n==1) return 1 ;
        
        map<int,int> mp1 ;
        unordered_set<int> st ;
        
        for(auto &it : trust){
            mp1[it[1]]++;
            st.insert(it[0]);
        }
        int indx = -1 ;
        for(auto &it : mp1){
            if(st.find(it.first)==st.end()){
                if(it.second == (n-1)) indx = it.first ;
            }
        }
        
        return indx ;
        
    }
};