class Solution {
  public:
    bool checkBFS(int index, vector<int>& vis, vector<int> adj[], int& V){
        queue<int> q;
        q.emplace(index);
        while(!q.empty()){
            int temp = q.front(), visCount = 0;
            q.pop();
            for(int i : adj[temp])
                if(vis[i]++ > 0) visCount++;
                else q.emplace(i);
            if(visCount > 1) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        for(int i = 0; i < V; i++)
            if(vis[i]++ == 0 && checkBFS(i, vis, adj, V)) return true;
        return false;
    }
};
