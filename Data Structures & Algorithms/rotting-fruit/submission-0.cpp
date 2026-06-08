class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        int freshOranges = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) freshOranges++;
                else if(grid[i][j] == 2) q.push({i, j});
            }
        }

        if(freshOranges == 0) return 0;

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        int minutes = 0;

        while(!q.empty()) {
            int size = q.size();
            bool rotted = false;

            while(size--) {
                auto [x, y] = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int i = x + dx[k];
                    int j = y + dy[k];

                    if(i >= 0 && j >= 0 && i < m && j < n && grid[i][j] == 1){ 
                        grid[i][j] = 2;
                        freshOranges--;
                        q.push({i, j});
                        rotted = true;
                    }
                }
            }
            if(rotted) minutes++;
        }

        return freshOranges == 0 ? minutes : -1;
    }
};
