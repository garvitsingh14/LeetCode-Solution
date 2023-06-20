class Solution {
public:
    int mod = 1e9 + 7;
    int delrow[4] = {-1, 1, 0, 0};
    int delcol[4] = {0, 0, -1, 1};
    
    int solve( int x, int y, int m, int n,vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        
        if (dp[x][y] != -1)
            return dp[x][y];
        
        long long ans = 1;
        
        for (int i = 0; i < 4; i++) {
            int nr = x + delrow[i];
            int nc = y + delcol[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[x][y] < grid[nr][nc]) {
                ans += solve( nr, nc, m, n,grid, dp);
            }
        }
        return dp[x][y] = ans % mod;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, -1));
        
        long long ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans += solve( i, j, m, n,grid, dp);
            }
        }
        return ans % mod;
    }
};