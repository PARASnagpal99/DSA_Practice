class Solution {
public:
    set<pair<int,int>>res ;
    void func (vector<int>& nums){
        int x = nums[0] , y = nums[1] , r = nums[2] ;
        for(int i=x-r ; i<=x+r ; ++i){
            for(int j=y-r ; j<=y+r ; ++j){
                if((x-i)*(x-i)+(y-j)*(y-j)<=r*r){
                    res.insert({i,j});
                }
            }
        }
    }
    
    int countLatticePoints(vector<vector<int>>& circles) {
               for(int i=0 ; i<circles.size() ; ++i){
                    func(circles[i]);
               }
        return res.size() ;
    }
};