class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> Map;
      for (auto &num: nums)
          Map[num]++;
      int ans = 0;
  
      for(auto it=Map.begin(); it!=Map.end(); ++it)
      {
        int num = it->first, count = it->second;
        if(k - num == num) ans += count/2;
        else
        {
            if(Map.count(k - num))
            {
              int Min = min(count, Map[k-num]);
              ans += Min;
              Map[num] -= Min;
              Map[k-num] -= Min;
            }
        }
      }
      return ans;
    }
};