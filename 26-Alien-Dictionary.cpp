class Solution{
    private:
    vector<int> topoSort(int V, vector<vector<int>> adj) {
        vector<int> indegree(V, 0), res;
        queue<int> q;
        for(int i = 0; i < V; i++) for(int it : adj[i]) indegree[it]++;
        for(int i = 0; i < V; i++) if(indegree[i] == 0) q.push(i);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            res.emplace_back(temp);
            for(int i : adj[temp]){
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
	    return res;
	}
    public:
    string findOrder(string dict[], int N, int K) {
        vector<vector<int>> adj(K);
        
        for(int i = 0; i < N-1; i++){
            string s1 = dict[i], s2 = dict[i+1];
            int len = min(s1.size(), s2.size()), p;
            for(p = 0; p < len; p++)
                if(s1[p] != s2[p]) {
                    adj[s1[p]-'a'].push_back(s2[p] - 'a');
                    break;
                }
        }
        
        vector<int> res = topoSort(K, adj);
        
        string order = "";
        for(auto i : res) order += char('a' + i);
        
        return order;
    }
};
