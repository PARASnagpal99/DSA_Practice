class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
         int n = nums.size() ;
         priority_queue<int> pq ;
         for(auto &it : nums){
             pq.push(it) ;
         }
        int ans ;
        while(pq.size() > n-k){
            ans = pq.top() ;
            pq.pop() ;
        }
        
        return ans ;
        
    }
};