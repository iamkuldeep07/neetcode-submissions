class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        queue<pair<int, int>> q;
        for(int i = 0; i < m; i++) if(board[i][0] == 'O') q.push({i, 0});
        for(int j = 0; j < n; j++) if(board[0][j] == 'O') q.push({0, j});
        for(int j = 0; j < n; j++) if(board[m - 1][j] == 'O') q.push({m - 1, j});
        for(int i = 0; i < m; i++) if(board[i][n - 1] == 'O') q.push({i, n - 1});

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            board[i][j] = '#';

            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 && y >= 0 && x < m && y < n && board[x][y] == 'O') q.push({x, y});    
            }
        }


        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == '#') board[i][j] = 'O';
                else board[i][j] = 'X';
            }
        }
    }
};
