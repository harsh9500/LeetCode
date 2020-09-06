class Solution {
public:
    // struct hash_pair
    // { 
    //     template <class T1, class T2> 
    //     size_t operator()(const pair<T1, T2>& p) const
    //     { 
    //         auto hash1 = hash<T1>{}(p.first); 
    //         auto hash2 = hash<T2>{}(p.second); 
    //         return hash1 ^ hash2; 
    //     } 
    // };
    vector<pair<int,int>> non_zero_cells(vector<vector<int>> M)
    {
        vector<pair<int,int>> ret;
        for (int row=0;row<M.size();++row)
            for (int col=0;col<M.size();++col)
                if (M[row][col] == 1)
                    ret.push_back({row, col});
        return ret;
    }
    
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<pair<int,int>> A_ones = non_zero_cells(A);
        vector<pair<int,int>> B_ones = non_zero_cells(B);

        int maxOverlaps = 0;
        map<pair<int,int>,int> groupCount;

        for (auto a : A_ones)
        {
            for (auto b : B_ones)
            {
                pair<int,int> vec={b.first-a.first,b.second-a.second};
                if (groupCount.find(vec)!=groupCount.end())
                {
                    groupCount[vec]++;
                } 
                else
                {
                    groupCount[vec]=1;
                }
                maxOverlaps = max(maxOverlaps, groupCount[vec]);
            }
        }
        return maxOverlaps;
    }
};