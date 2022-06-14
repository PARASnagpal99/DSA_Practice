class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size() ;
        queue<int> q ;
        q.push(start);
        vector<bool> vis(n,0);
        
        
        
        while(!q.empty()){
            int curr = q.front() ;
            q.pop() ;
            if(arr[curr] == 0) return true ;
            if(vis[curr]) continue ;
            
            if(curr + arr[curr] >=0 && curr + arr[curr] < n) q.push(curr + arr[curr]) ;
            if(curr - arr[curr] >=0 && curr - arr[curr] < n) q.push(curr - arr[curr]) ;
            
            vis[curr] = true ;
        }
        
        return false ;
    }
};