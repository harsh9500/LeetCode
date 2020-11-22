class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> s;
        string temp;
        for(string word:words)
        {
            temp="";
            for(char alphabet:word)
            {
                temp+=codes[alphabet-'a'];
            }
            s.insert(temp);
        }
        return s.size();
    }
};