class Solution {
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int> st ;
        for(auto &it : forbidden)st.insert(it);
        
        queue<pair<int,int>>q ;
        q.push({0,0}) ;    // 0 means can go backward 
        st.insert(0) ;
        int ans = 0 ;
        while(!q.empty()){
            int sz = q.size() ;
            while(sz--){
                int curr = q.front().first ;
                int state = q.front().second ;
                q.pop();
                if(curr == x) return ans ;
                
                int forward = curr + a , backward = curr - b ;
                
                if(state==0 && backward >=0 && !st.count(backward) ){
                     st.insert(backward) ; 
                     q.push({backward,1});
                }
                
                if(forward <= 6000  && !st.count(forward)){
                    st.insert(forward) ; 
                    q.push({forward,0});
                }
                
            }
            ans++;
        }
        
        return -1 ;
    }
};