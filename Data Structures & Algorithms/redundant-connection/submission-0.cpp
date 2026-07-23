class Solution {
private:
    bool dfs(int src, int target, vector<vector<int>>& adj, vector<int>& vis){
        vis[src] = 1;

        if(src == target){
            return true;
        }
        for(auto it : adj[src]){
            if(!vis[it] && dfs(it, target, adj, vis)){
                return true;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(n+1);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            vector<int>vis(n+1, 0);

            if(!adj[u].empty() && !adj[v].empty() && dfs(u, v, adj, vis)){
                return {u, v};
            }

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};
