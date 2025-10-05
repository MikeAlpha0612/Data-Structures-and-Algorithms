class Solution {
public: 

    void dfs(vector<vector<int>>& heights, int m, int n, int row, int col, int dx[], int dy[], vector<vector<int>>&visited){
        
        visited[row][col] = 1 ;

        for(int i = 0; i < 4; i++){
            int nrow = row + dx[i];
            int ncol = col + dy[i];

           if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && !visited[nrow][ncol] && heights[nrow][ncol] >= heights[row][col] ){
            dfs(heights, m, n, nrow, ncol, dx, dy, visited);
           }
        }


    }




    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      
      int m = heights.size();
      int n = heights[0].size();

      vector<vector<int>>canReachPacific(m, vector<int>(n,0));
      vector<vector<int>>canReachAtlantic(m, vector<int>(n,0));

      int dx[4] = {0,-1,0,1};
      int dy[4] = {1,0,-1,0};

      for(int i = 0; i < n; i++){
         dfs(heights, m, n, 0 , i, dx, dy,canReachPacific );
      }
      
         for(int i = 0; i < n; i++){
         dfs(heights, m, n, m-1 , i, dx, dy, canReachAtlantic);
      }

        for(int i = 0; i < m; i++){
         dfs(heights, m, n, i , 0, dx, dy, canReachPacific);
      }

          for(int i = 0; i < m; i++){
         dfs(heights, m, n, i , n-1, dx, dy, canReachAtlantic);
      }

      vector<vector<int>>result;

      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(canReachPacific[i][j] && canReachAtlantic[i][j]){
                 result.push_back({i,j});
            }
        }
      }


  return result;

  }


};