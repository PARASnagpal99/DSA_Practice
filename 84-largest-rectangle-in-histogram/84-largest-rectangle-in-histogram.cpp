class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
         int ans = 0 ;
         int n = heights.size() ;
        
        stack<int> st ;
        
        for(int i=0 ; i <= n ; ++i){
            
            while(!st.empty() && (i==n || heights[st.top()] > heights[i] )){
                
                int height = heights[st.top()];
                st.pop() ;
                int width ;
                if(st.empty()) width = i ; // no left smaller element 
                else {
                    width = i - st.top() - 1 ;  // index of right greater element - index of left smaller element - 1 
                }
                
                ans = max(ans , width * height);
                
            }
            if(i!=n) st.push(i);
        }
        
       return ans ; 
    }
};