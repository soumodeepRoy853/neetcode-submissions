class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>>q;
        // Left and Right boundary
        for(int i=0; i<n; i++){
            if(board[i][0] == 'O'){
                q.push({i, 0});
                board[i][0] = '#';
            }
            if(board[i][m-1] == 'O'){
                q.push({i, m-1});
                board[i][m-1] = '#';
            }
        }

        //Top and Bottom Boundary
        for(int j=0; j<m; j++){
            if(board[0][j] == 'O'){
                q.push({0, j});
                board[0][j] = '#';
            }

            if(board[n-1][j] == 'O'){
                q.push({n-1, j});
                board[n-1][j] = '#';
            }
        }

        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];

                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol] == 'O'){
                    board[nrow][ncol] = '#';
                    q.push({nrow, ncol});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '#'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
