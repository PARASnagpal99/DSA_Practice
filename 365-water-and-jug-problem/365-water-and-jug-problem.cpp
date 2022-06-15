class Solution {
public:
    bool canMeasureWater(int i , int j , int k) {
        unordered_set<int>s;
        queue<int>q;
        q.push(i+j);
        
        while(!q.empty()) {
            int curr = q.front();
            s.insert(curr);
            q.pop();
            
            vector<int>options = {i,-i,j,-j};
            for(auto x : options) {
                int next = curr+x;
                next = max(0,next);
                next = min(i+j,next);
                
                if(next == k) return true;
                
                if(s.find(next) == s.end()) q.push(next);
            }
        }
        return false;
    }
};