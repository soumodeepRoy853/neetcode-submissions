class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<vector<pair<int, int>>> adj(n+1);
        for(auto edge : times){
            int u = edge[0];
            int v = edge[1];
            int t = edge[2];

            adj[u].push_back({v, t});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            int node = pq.top().second;
            int time = pq.top().first;
            pq.pop();

            for(auto it : adj[node]){
                int edgeTime = it.second;
                int adjNode = it.first;

                if(time+edgeTime < dist[adjNode]){
                    dist[adjNode] = time+edgeTime;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        int ans = 0;
        for(int i=1; i<=n; i++){
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};
