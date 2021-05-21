class Solution {
public:
    bool match(string word, string pattern)
    {
        unordered_map<char, char> M;
        for (int i = 0; i < word.length(); i++)
        {
            char w = word[i];
            char p = pattern[i];
            if (M.find(w)==M.end())
                M[w] = p;
            if (M[w] != p)
                return false;
        }

        bool seen[26];
        memset(seen,false,sizeof(seen));
        for (auto p: M)
        {
            if (seen[p.second - 'a'])
                return false;
            seen[p.second - 'a'] = true;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> answer;
        for (string word: words)
            if (match(word, pattern))
                answer.push_back(word);
        return answer;
    }
};