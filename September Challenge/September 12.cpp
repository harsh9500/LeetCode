class Solution {
public:
    void backtrack(int n, int k, vector<vector<int>> & answer, vector<int> & comb, int next)
    {
        if(n==0 && comb.size()==k)
        {
            answer.push_back(comb);
            return;
        }
        if(n<0 || comb.size()==k)
            return;
        for(int i=next;i<9;i++)
        {
            comb.push_back(i+1);
            backtrack(n-i-1,k,answer,comb,i+1);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        vector<vector<int>> answer;
        backtrack(n,k,answer,comb,0);
        return answer;
    }
};