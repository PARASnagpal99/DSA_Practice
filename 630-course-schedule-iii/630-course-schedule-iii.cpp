class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size() ;
        sort(courses.begin(),courses.end() , [&] (vector<int> &a , vector<int> &b){
               return a[1] < b[1] ;
        });
        
        int cnt = 0 ;
        int curr_time = 0 ;
        
        priority_queue<int> pq ;
        
        for(int i=0 ; i<n ; ++i){
            curr_time+=courses[i][0] ;
            pq.push(courses[i][0]) ;
            cnt++;
            while(curr_time > courses[i][1]){
                int x = pq.top() ;
                curr_time-=x ;
                cnt--;
                pq.pop() ;
            }
            
        }
        
        return cnt ;
    }
};