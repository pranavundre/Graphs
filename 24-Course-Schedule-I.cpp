class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &adj) {
        vector<int> indegree(V, 0);
        int sumDegrees = 0;
        queue<int> q;
        for(int i = 0; i < V; i++){
            for(int it : adj[i]){
                indegree[it]++;
                sumDegrees++;
            }
        }
        for(int i = 0; i < V; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i : adj[temp]){
                indegree[i]--;
                sumDegrees--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        return sumDegrees==0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(auto a : prerequisites){
            adj[a[1]].emplace_back(a[0]);
        }
        return isCyclic(numCourses, adj);
    }
};
