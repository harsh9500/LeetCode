class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2)
            return 0;
        int firstBuy=INT_MIN;
        int firstSell=0;
        int secondBuy=INT_MIN;
        int secondSell=0;
        for(int i=0;i<n;i++)
        {
            firstBuy=max(firstBuy,-prices[i]);
            firstSell=max(firstSell,firstBuy+prices[i]);
            secondBuy=max(secondBuy,firstSell-prices[i]);
            secondSell=max(secondSell,secondBuy+prices[i]);
        }
        return secondSell;
    }
};