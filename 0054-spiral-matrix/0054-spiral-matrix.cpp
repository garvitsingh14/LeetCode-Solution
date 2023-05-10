class Solution {
public:
    vector<int> ans;
    int n,m;

    void dfs(int i,int j,vector<vector<int>> &mat,vector<vector<int>> &visited)
    {
        if(i<0 || i >= n || j<0 || j >= m || visited[i][j] )
          return ;
        
        visited[i][j] = 1;
        ans.push_back(mat[i][j]);

        if (i <= j + 1)
            dfs(i,j+1,mat,visited);
        dfs(i+1,j,mat,visited);
        dfs(i,j-1,mat,visited);
        dfs(i-1,j,mat,visited);
        
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int i = 1;
        int j = 0;
        
        n = matrix.size();
        m = matrix[0].size();

        vector<vector<int>> visited(n,vector<int> (m,0));
        dfs(0,0,matrix,visited);
        

        return ans;
    }
};