class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int> &vis){
        vis[node] = 1;

        for(auto it : adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int cnt = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
    }
};
