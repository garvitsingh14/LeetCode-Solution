class Solution {
public:
    int delrow[4] = {-1,0,1,0};
    int delcol[4] = {0,1,0,-1};

    int dfs(int i, int j, vector<vector<int>> &matrix,vector<vector<int>> &dp)
    {
        
        if(dp[i][j]!=-1)
            return dp[i][j];

        int ans = 0;

        for(int k = 0; k < 4 ; k++)
        {
            int nr = i + delrow[k];
            int nc = j + delcol[k];

            if(nr >= 0 && nr < matrix.size() 
                && nc >=0 && nc < matrix[0].size() 
                && matrix[nr][nc] > matrix[i][j])
            {
                ans = max(ans, 1 + dfs(nr,nc,matrix,dp));
            }
        }
        return dp[i][j] = ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int> (m,-1));

        int ans = 0;
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                ans = max(ans,dfs(i,j,matrix,dp));

        return ans+1;
    }
};