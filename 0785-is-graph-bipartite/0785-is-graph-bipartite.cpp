class Solution {
public:
    bool bfs(int node,vector<int> &color,vector<vector<int>>& graph )
    {
        color[node]=0;
        queue<int> q;
        q.push(node);

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto i:graph[front])
            {
                if(color[i] == -1)
                {
                    color[i] = !color[front];
                    q.push(i);
                }
                else if(color[i] == color[front])
                 return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();

        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(i,color,graph))
                    return false;
            }
        }
        return true;
    }
};