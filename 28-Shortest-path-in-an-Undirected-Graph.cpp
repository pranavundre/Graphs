class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        vector<int> dist(N, INT_MAX), vis(N, 0);
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        vis[src] = 1;
        
        for(auto p : edges){
            adj[p[0]].emplace_back(p[1]);
            adj[p[1]].emplace_back(p[0]);
        }

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i : adj[temp]){
                dist[i] = min(dist[i], 1 + dist[temp]);
                if(vis[i]++ == 0) q.push(i);
            }
        }
        
        for(int i = 0; i < N; i++)
            if(vis[i] == 0) dist[i] = -1;
        
        return dist;
    }
};
