class Solution {
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    void dfs(int i, int j, vector<vector<int>>& grid, int& area) {
        grid[i][j] = 0;
        area++;

        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if(x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size() && grid[x][y]) {
                dfs(x, y, grid, area);
            }
        }
        return;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, grid, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
