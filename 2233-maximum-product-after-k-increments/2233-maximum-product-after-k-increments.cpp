class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
         // min heap
         priority_queue <int, vector<int>, greater<int>> pq ;
         
        for(auto &it : nums) pq.push(it) ;    
        int mod = 1e9 + 7 ;
        
        while(k--){
            auto curr = pq.top() ;
            pq.pop();
            pq.push(curr + 1) ;
        }
        
        vector<int> res ;
        while(!pq.empty()){
            auto curr = pq.top() ;
            res.push_back(curr) ;
            pq.pop() ;
        }
        
        long long ans = 1 ;
        for(auto &it : res){
            ans = (ans * it) % mod ;
        }
        
        ans = ans%mod ;
        return (int)ans ;
        
    }
};