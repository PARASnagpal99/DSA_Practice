class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
       // map<int,vector<int>>mp;
        
        vector<vector<int>> mp(101);
        
        for(auto &it : rectangles){
            mp[it[1]].push_back(it[0]);
        }
        
        for(auto &it : mp){
            sort(it.begin(),it.end());
        }
        vector<int>res ;
        for(auto &it : points){
          int cnt = 0 ;
          for(int i=it[1] ; i<=100 ; ++i){
              auto finish = lower_bound(mp[i].begin(),mp[i].end(),it[0]) ;
              cnt+=(mp[i].end()-finish);
          }
          res.push_back(cnt);
        }
        
        return res;
        
    }
};