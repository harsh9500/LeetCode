class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        if(n<2)
            return 0;
        int maxProfit=INT_MIN;
        int minPrice=prices[0];
        for(int i=0;i<n;i++)
        {
            maxProfit=max(maxProfit,prices[i]-minPrice);
            minPrice=min(minPrice,prices[i]);
        }
        return maxProfit;
    }
};