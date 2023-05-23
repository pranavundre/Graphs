class Solution {
  public:
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adj(N);
        for(int i = 0; i < M; i++) adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        
        vector<int> dist(N, INT_MAX);
        queue<int> q;
        q.push(6);
        dist[6] = 0;
        vector<int> vis(N, 0);
        vis[6] = 1;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            int prev = dist[temp];
            for(auto p : adj[temp]){
                int e = p.first;
                int d = p.second;
                dist[e] = min(dist[e], d+prev);
                if(!vis[e]){
                    q.push(e);
                    vis[e] = 1;
                }
            }
        }
        
        for(int i = 0; i < N; i++) if(vis[i] == 0) dist[i] = -1;
        
        return dist;
        
    }
};
