class Solution {
public:
    long long solve(int index,vector<vector<int>> &ques,vector<long long> &dp)
    {
        if(index >= ques.size())
            return 0;

        if(dp[index]!=-1)
            return dp[index];
        
        long long in = ques[index][0] + solve(index + ques[index][1] + 1 ,ques,dp);
        long long ex = solve(index+1,ques,dp);

        return dp[index]=max(in,ex);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        long long ans = 0;
        vector<long long> dp(questions.size()+1,-1);
        ans = solve(0,questions,dp);
        return ans;
    }
};

