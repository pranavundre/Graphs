class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        queue<vector<string>> q;
        
        vector<vector<string>> res;
        vector<string> temp;
        temp.push_back(beginWord);
        
        set<string> words(wordList.begin(), wordList.end());
        
        if(!words.count(endWord)) return res;
        
        q.push(temp);
        
        words.erase(beginWord);
        
        int n = beginWord.size();
        int lvl = -1;
        
        while (!q.empty()) {
            int size = q.size();
            lvl++;
            string mod;
            vector<string> del;
            
            while (size--) {
                
                vector<string> lastVec = q.front();
                string last = lastVec[lvl];
                
                q.pop();
                
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < 26; j++) {
                        mod = last.substr(0, i) + char('a' + j) + last.substr(i + 1);
                        if (mod.compare(endWord) == 0){
                            lastVec.emplace_back(mod);
                            res.emplace_back(lastVec);
                        }
                        else if (mod.compare(last) != 0 && words.count(mod)) {
                            lastVec.emplace_back(mod);
                            q.push(lastVec);
                            lastVec.pop_back();
                            del.emplace_back(mod);
                        }
                    }
                }
            }
            
            for(string s : del) words.erase(s);
        }
        return res;
    }
};
