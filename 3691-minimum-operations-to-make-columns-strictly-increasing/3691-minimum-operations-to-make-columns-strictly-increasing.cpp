class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for (int j = 0; j < m; j++) {
            for (int i = 1; i < n; i++) {
                if (grid[i][j] <= grid[i - 1][j]) {
                    ans += (grid[i - 1][j] - grid[i][j]) + 1;
                    grid[i][j] = grid[i - 1][j] + 1;
                }
            }
        }
        return ans;
    }
};