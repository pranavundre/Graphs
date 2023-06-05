class Solution{
	public:
    int spanningTree(int V, vector<vector<int>> adj[]){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> vis(V, 0);

        int minSum = 0;
        pq.push({0, 0});
        
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            
            int d = p.first, node = p.second;
            
            if(vis[node] == 1) continue;
            
            vis[node]++;
            minSum += d;
            
            for(auto vec : adj[node]) if(vis[vec[0]] == 0) pq.push({vec[1], vec[0]});
        }
        return minSum;
    }
};
