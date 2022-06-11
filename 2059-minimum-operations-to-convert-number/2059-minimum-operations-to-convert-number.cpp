class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int res = 0 ;
        queue<int> q ;
        vector<bool> visit(1005,false) ;
        q.push(start);
        
        while(!q.empty()){
            int sz = q.size() ;
            while(sz--){
                auto curr = q.front() ;
                q.pop() ;
                if(curr==goal) return res ;         
                
                if(curr > 1000 or curr < 0 or visit[curr]) continue ;
                
                visit[curr] = true ;
                
                for(int i=0 ; i<nums.size() ; ++i){
                    int a = curr + nums[i] ;
                    int b = curr - nums[i] ;
                    int c = curr ^ nums[i] ;
                    if(goal == a) return res+1 ;
                    if(goal == b) return res+1 ;
                    if(goal == c) return res+1 ;
                    if(a <= 1000 && a >= 0 && !visit[a]) q.push(a);
                    if(b <= 1000 && b >= 0 && !visit[b]) q.push(b);
                    if(c <= 1000 && c >= 0 && !visit[c]) q.push(c);
                }
            }
            res++; 
        }
        
        return -1 ;
        
    }
};