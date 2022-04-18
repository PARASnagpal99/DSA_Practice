class Solution {
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
     
  vector<vector<pair<int,int>>> pref = vector(grid.size(),vector<pair<int,int>>(grid[0].size()));
  vector<vector<pair<int,int>>> suff = vector(grid.size(),vector<pair<int,int>>(grid[0].size()));
  
  
  for(int i=0;i<grid.size();i++)
  {
    for(int j=0;j<grid[0].size();j++)
    {
       int two=0,five=0;
       int x = grid[i][j];
      while(x%2 == 0) two++, x=x/2;
      while(x%5 == 0) five++,x=x/5;
      pref[i][j] = {two,five};
      if(j!=0)
      {
        pref[i][j] = {pref[i][j].first+pref[i][j-1].first,pref[i][j].second+pref[i][j-1].second};
      }
    }
  }
  
  
  
  for(int i=0;i<grid.size();i++)
  {
    for(int j=grid[0].size()-1;j>=0;j--)
    {
       int two=0,five=0;
       int x = grid[i][j];
      while(x%2 == 0) two++, x=x/2;
      while(x%5 == 0) five++,x=x/5;
      suff[i][j] = {two,five};
      if(j!=(grid[0].size()-1))
      {
        suff[i][j] = {suff[i][j].first+suff[i][j+1].first,suff[i][j].second+suff[i][j+1].second};
      }
    }
  }
  
  int ans = 0;
  int count2=0,count5=0;
  for(int i=0;i<grid[0].size();i++)
  {
     count2=0,count5=0;
     for(int j=0;j<grid.size();j++)
     {
       
       ans = max(ans,min(count2+pref[j][i].first,count5+pref[j][i].second));
       ans = max(ans,min(count2+suff[j][i].first,count5+suff[j][i].second));
       int two=0,five=0;
       int x = grid[j][i];
       while(x%2 == 0) two++, x=x/2;
       while(x%5 == 0) five++,x=x/5;
       count2 += two;
       count5 += five;
     }
  }
  
  count2=0,count5=0;
  for(int i=0;i<grid[0].size();i++)
  {
     count2=0,count5=0;
     for(int j = grid.size()-1;j>=0;j--)
     {
       
       ans = max(ans,min(count2+pref[j][i].first,count5+pref[j][i].second));
       ans = max(ans,min(count2+suff[j][i].first,count5+suff[j][i].second));
       int two=0,five=0;
       int x = grid[j][i];
       while(x%2 == 0) two++, x=x/2;
       while(x%5 == 0) five++,x=x/5;
       count2 += two;
       count5 += five;
     }
  }
  
  return ans;
  
  }
};