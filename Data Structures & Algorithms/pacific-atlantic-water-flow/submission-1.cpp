class Solution {
private:
    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& vis){
        int n = heights.size();
        int m = heights[0].size();

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if( nrow>=0 && nrow<n && ncol>=0 && ncol<m &&
                    !vis[nrow][ncol] && heights[nrow][ncol] >= heights[r][c]){
                        vis[nrow][ncol] = true;
                        q.push({nrow, ncol});
                    }
            }
        } 
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacificVis(n, vector<bool>(m, false));
        vector<vector<bool>> atlanticVis(n, vector<bool>(m, false));

        queue<pair<int, int>> pacificQueue;
        queue<pair<int, int>> atlanticQueue;

        //Pacific top row
        for(int i=0; i<n; i++){
            pacificQueue.push({i, 0});
            pacificVis[i][0] = true;
        }

        //Pacific first col
        for(int j=1; j<m; j++){
            pacificQueue.push({0, j});
            pacificVis[0][j] = true;
        }

        //Atlantic bottom row
        for(int i=0; i<n; i++){
            atlanticQueue.push({i, m-1});
            atlanticVis[i][m-1] = true;
        }

        //Atlantic last col
        for(int j=0; j<m; j++){
            atlanticQueue.push({n-1, j});
            atlanticVis[n-1][j] = true;
        }

        bfs(heights, pacificQueue, pacificVis);
        bfs(heights, atlanticQueue, atlanticVis);

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pacificVis[i][j] && atlanticVis[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};
