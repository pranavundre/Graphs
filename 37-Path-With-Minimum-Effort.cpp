class Solution {
public:
    vector<int> dir{0, 1, 0, -1, 0};
    int minimumEffortPath(vector<vector<int>>& ht) {
        int n = ht.size(), m = ht[0].size();

        vector<vector<int>> eff(n, vector<int> (m, INT_MAX));
        eff[0][0] = 0;

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        pq.push({0, {0, 0}});

        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            int d = p.first, r = p.second.first, c = p.second.second;
            if(r == n-1 && c == m-1) return d;

            if(eff[r][c] < d) continue;

            for(int i = 0; i < 4; i++){
                int nr = r + dir[i], nc = c + dir[i+1];

                if(nr>=0 && nc>=0 && nr<n && nc<m && max(d, abs(ht[r][c]-ht[nr][nc])) < eff[nr][nc]){
                    eff[nr][nc] = max(d, abs(ht[r][c]-ht[nr][nc]));
                    pq.push({eff[nr][nc], {nr, nc}});
                }
            }
        }
        return -1;
    }
};
