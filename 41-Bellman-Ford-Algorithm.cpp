class Solution {
    public:
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        for(int i = 0; i < V-1; i++)
            for(auto vec : edges)
                dist[vec[1]] = min(dist[vec[1]], dist[vec[0]]+vec[2]);
                
        for(auto vec : edges) if(dist[vec[1]] > dist[vec[0]] + vec[2]) return{-1};
        
        return dist;
    }
};
