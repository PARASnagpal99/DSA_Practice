class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size() ;
        const int dir[5] = {1,0,-1,0,1};
    //    int res = 0 ;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq ;
        vector<vector<bool>> visited(n, vector<bool>(m, false)); 
        pq.push({0,0});
        int ans = -1 ;
         while(!pq.empty())
        {
            pair<int, int> tp = pq.top();
            pq.pop();
            
            int x = tp.second/100;
            int y = tp.second%100;
            
            if(visited[x][y]==true) continue;
            
            visited[x][y] = true;
            
            if(x==n-1 && y == m-1)
            {
                ans = tp.first;
                break;
            }
            
            for(int i=0; i<4; i++)
            {
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                
                int npos = nx*100+ny;

	
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
                pq.push({max(tp.first, abs(heights[nx][ny]-heights[x][y])), npos});
            }
        }
        
        return ans;
    }
    
};