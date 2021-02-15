class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int n=mat.size();
        int m=mat[0].size();
        vector<pair<int,int>> v;
        vector<int> answer;
        for(int i=0;i<n;i++)
        {
            int soldiers=0;
            for(int j=0;j<m && mat[i][j]!=0;j++)
            {
                soldiers++;
            }
            v.push_back(make_pair(soldiers,i));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<k;i++)
        {
            answer.push_back(v[i].second);
        }
        return answer;
    }
};