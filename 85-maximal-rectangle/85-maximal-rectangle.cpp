class Solution {
public:
    
    
    int maxRectangleArea(vector<int>& nums){
        int n = nums.size() ;
        stack<int> st ;
        int res = 0 ;
        
        for(int i=0 ; i<=n ; ++i){
            
            while(!st.empty() && (i==n or nums[st.top()] > nums[i])){
                int ht = nums[st.top()];
                st.pop();
                int width ;
                if(st.empty()) width = i ;
                else width = i - st.top() - 1 ;
                
                res = max(res , width * ht );
            }
            
            st.push(i);
        } 
       return res ; 
    }
    
    int maximalRectangle(vector<vector<char>>& matrix){
        
        int n = matrix.size() , m = matrix[0].size() ;
        
        int maxArea = 0 ;
        vector<int> dp(m,0);
        
        for(int i=0 ; i < n ; ++i){
            
            for(int j=0 ; j<m ; ++j){
                if(matrix[i][j]=='1') dp[j]++;
                else dp[j] = 0 ;
            }
            int area = maxRectangleArea(dp);
            maxArea = max(area,maxArea);
        }
        
        
        return maxArea ;
        
    }
};