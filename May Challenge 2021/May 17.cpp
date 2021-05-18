class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;

        sort(words.begin(), words.end(), [](const string &word1, const string &word2) {
            return word1.size() < word2.size();
        });

        int longestWordSequenceLength = 1;

        for (const string &word : words)
        {
            int presentLength = 1;
            
            for (int i = 0; i < word.length(); i++)
            {
                string predecessor = word.substr(0, i) + word.substr(i + 1, word.length() + 1);
                if (dp.find(predecessor) != dp.end()) {
                    int previousLength = dp[predecessor];
                    presentLength = max(presentLength, previousLength + 1);
                }
            }
            dp[word] = presentLength;
            longestWordSequenceLength = max(longestWordSequenceLength, presentLength);
        }
        return longestWordSequenceLength;
    }
};