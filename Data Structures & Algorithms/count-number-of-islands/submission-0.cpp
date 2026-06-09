class Solution {
private:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        vis[row][col] = 1;

        queue<pair<int, int>>q;
        q.push({row, col});

        int delRow[] = {-1, 0, +1, 0};
        int delCol[] = {0, +1, 0, -1};

        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && 
                !vis[nRow][nCol] && grid[nRow][nCol] == '1'){
                    vis[nRow][nCol] = 1;
                    q.push({nRow, nCol});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        vector<vector<int>>vis(m, vector<int>(n, 0));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    count++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return count;
    }
};
