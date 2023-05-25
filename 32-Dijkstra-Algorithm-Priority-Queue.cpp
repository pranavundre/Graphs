class Solution{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S){
        vector<int> dist(V, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, S});
        dist[S] = 0;
        while(!pq.empty()){
            auto p = pq.top();
            int d = p.first, node = p.second;
            pq.pop();
            if(dist[node] < d) continue;
            for(auto vec : adj[node]){
                if(vec[1] + d < dist[vec[0]]){
                    dist[vec[0]] = vec[1] + d;
                    pq.push({dist[vec[0]], vec[0]});
                }
            }
        }
        return dist;
    }
};
