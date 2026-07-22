class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        //push all gates into q
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        //visit all neighbours
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        //Traverse whole q
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 2147483647){
                    grid[nrow][ncol] = grid[r][c]+1;
                    q.push({nrow, ncol});
                }
            }
        }
    }
};
