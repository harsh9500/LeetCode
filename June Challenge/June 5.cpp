class Solution {
public:
    vector<int> sum;
    Solution(vector<int>& w) {
        int n=w.size();
        sum.push_back(w[0]);
        for(int i=1;i<n;i++)
        {
            sum.push_back(sum.back()+w[i]);
        }
    }
    
    int pickIndex() {
        int mod=sum.back();
        int r=rand()%mod;
        return upper_bound(sum.begin(),sum.end(),r)-sum.begin();
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */