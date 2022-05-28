class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size() ;
        intervals.push_back(newInterval) ;
        sort(intervals.begin(),intervals.end()) ;
        vector<vector<int>>res ;
        res.push_back(intervals[0]);
        for(int i=1 ; i<n+1 ; ++i){
            if(intervals[i][0]<=res.back()[1]) res.back()[1] = max(res.back()[1],intervals[i][1]) ;
            else res.push_back(intervals[i]);
        }
        return res ;
    }
};