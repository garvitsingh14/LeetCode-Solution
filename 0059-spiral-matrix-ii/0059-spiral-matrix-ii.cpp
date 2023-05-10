class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        int srow = 0, erow = n-1;
        int scol = 0, ecol = n-1;
        int count = 1, total = n*n;

        while(count <= total)    {
            for(int i=scol; i<=ecol && count<=total; i++)   
                ans[srow][i] = count++;
            srow++;

            for(int i=srow; i<=erow && count<=total; i++) 
                ans[i][ecol] = count++;
            ecol--;

            for(int i=ecol; i>=scol && count<=total; i--) 
                ans[erow][i] = count++;
            erow--;

            for(int i=erow; i>=srow && count<=total; i--) 
                ans[i][scol] = count++;
            scol++;
        }

        return ans;
    }
};