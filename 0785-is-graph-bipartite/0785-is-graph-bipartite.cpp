class Solution {
public:
    bool bfs(int node,vector<int> &color, unordered_map<int,list<int>> adj)
    {
        color[node]=0;
        queue<int> q;
        q.push(node);

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto i:adj[front])
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
        unordered_map<int,list<int>> adj;
        int n = graph.size();
        int m = graph[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<graph[i].size();j++)
            {
                adj[i].push_back(graph[i][j]);
            }
        }
        for(auto i:adj)
        {
            cout<<i.first<<"-> ";
            for(auto j:adj[i.first])
            {
                cout<<j<<", ";
            }cout<<endl;
        }

        vector<int> color(n,-1);
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!bfs(i,color,adj))
                    return false;
            }
        }
        return true;
    }
};