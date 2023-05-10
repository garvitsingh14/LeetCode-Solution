class Solution {
public:
    vector<string> ans;
    void solve(int open,int close,string temp)
    {
        if(open == 0 && close == 0)
        {
            ans.push_back(temp);
            // cout<<temp<<endl;
            return ;
        }
        if(open > 0)
            solve(open-1,close,temp+"(");
        if(close > 0 && close > open)
            solve(open,close-1,temp+")");
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        solve(n,n,temp);
        return ans;
    }
};