//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<string> ans;
    void solve(int index,string &s,string &temp)
    {
        if(index >= s.length())
        {
            ans.push_back(temp);
            return ;
        }
        
        // include 
        temp+=" ";
        temp+=s[index];
        solve(index+1,s,temp);
        temp.pop_back();
        temp.pop_back();
        
        // exclude
        temp+=s[index];
        solve(index+1,s,temp);
        temp.pop_back();
        
    }
    vector<string> permutation(string S){
        // Code Here
        
        string temp = "";
        temp += S[0];
        solve(1,S,temp);
        
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends