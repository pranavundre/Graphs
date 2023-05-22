class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<vector<int>> graph1(v);
        for(int i = 0; i < v; i++) for(int a : graph[i]) graph1[a].push_back(i);

        queue<int> q;
        vector<int> indegreeCount(v, 0), res;
        
        for(auto vec : graph1) for(auto i : vec) indegreeCount[i]++;
        for(int i = 0; i < v; i++) if(indegreeCount[i] == 0) q.push(i);
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            res.emplace_back(temp);
            for(int i : graph1[temp]) if(--indegreeCount[i] == 0) q.push(i);
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};
