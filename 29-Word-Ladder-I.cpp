class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        queue<string> q;
        set<string> words(wordList.begin(), wordList.end());
        if(!words.count(targetWord)) return 0;
        q.push(startWord);
        int n = startWord.size(), lvl = 1;
        while (!q.empty()) {
            int size = q.size();
            lvl++;
            string mod;
            while (size--) {
                string temp = q.front();
                q.pop();
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < 26; j++) {
                        mod = temp.substr(0, i) + char('a' + j) + temp.substr(i + 1);
                        if (mod.compare(targetWord) == 0) return lvl;
                        if (mod.compare(temp) != 0 && words.count(mod)) {
                            words.erase(mod);
                            q.push(mod);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
