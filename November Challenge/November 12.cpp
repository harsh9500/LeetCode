class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> s;
        do
        {
            s.push_back(nums);
        }while(next_permutation(nums.begin(),nums.end()));
        return s;
    }
};