class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates

      int m=grid.size();
      int n=grid[0].size();

      queue<pair<int,int>> q;
      int fresh=0; //to keep track of all fresh oranges left

      for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
          if(grid[i][j]==2){
            q.push({i,j});
          }
          if(grid[i][j]==1){
            fresh++;
          }
        }
      }

      int ans=-1;
      while(!q.empty()){
        int sz=q.size();

        while(sz--){
          pair<int,int> p=q.front();
          q.pop();

          for(int i=0;i<4;i++){
            int nr = p.first + dir[i];
            int nc = p.second + dir[i+1];

            if(nr>=0 and nr<m and nc>=0 and nc<n and grid[nr][nc]==1){
              grid[nr][nc] = 2;
              q.push({nr,nc});
              fresh--;
            }
          }
        }
        ans++;
      }
      if(fresh>0) return -1;
      if(ans==-1) return 0;
      return ans;
    }
};