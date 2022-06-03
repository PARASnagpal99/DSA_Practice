class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int len) {
            int n = tiles.size() ;
            int start = 0 , end = 0 ;
            int res = INT_MIN ;
            int sum = 0 ;
        sort(tiles.begin(),tiles.end());
        while(end < n && res<len){
            
            if(tiles[start][0] + len > tiles[end][1]){
                 sum += (tiles[end][1]-tiles[end][0]+1) ;
                 res = max(res,sum) ;
                 end++;
            }else{
                int partial = max(0,tiles[start][0]+len-tiles[end][0]) ;
                res = max(res,sum+partial) ;
                sum-=(tiles[start][1]-tiles[start][0]+1);
                start++;
            }
            
        }
         
        return res ;
    }
};