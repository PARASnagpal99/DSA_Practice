class Solution {
typedef pair<int, int> pi;
    
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size() ;
        
        vector<int> res ;
        
        for(int i=0 ; i<n ; ++i){
             tasks[i].push_back(i) ;
        }
        
        sort(tasks.begin(),tasks.end());
        
        long long time = 1 ;
        
        int indx = 0 ;
        
       priority_queue<pi, vector<pi>, greater<pi> > pq;
        
        while(indx < n or !pq.empty()){
            
            while(indx < n  && tasks[indx][0] <= time ){
                pq.push(make_pair(tasks[indx][1],tasks[indx][2]));
                indx++;
            }
            
            if(!pq.empty()){
                auto curr = pq.top() ;
                pq.pop() ;
                time += (curr.first) ;
                res.push_back(curr.second);
                
            }else{
                
                time = tasks[indx][0] ;
                
            }
            
        }
        
        return res ;
        
    }
};