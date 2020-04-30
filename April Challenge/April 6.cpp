class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > store; 
        for (int i = 0; i < strs.size(); i++) 
        {
            string tempString(strs[i]); 
            sort(tempString.begin(), tempString.end()); 
        
            if (store.find(tempString) == store.end())
            { 
                vector<string> temp_vec; 
                temp_vec.push_back(strs[i]); 
                store.insert(make_pair(tempString, temp_vec)); 
            } 
            else
            { 
                vector<string> temp_vec(store[tempString]); 
                temp_vec.push_back(strs[i]); 
                store[tempString] = temp_vec; 
            } 
        }
        vector<vector<string>> answer;
        for(auto j=store.begin();j!=store.end();j++)
        {
            answer.push_back(j->second);
        }
        return answer;
    }
};