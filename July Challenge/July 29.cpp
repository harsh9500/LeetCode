class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n<2)
            return 0;
        int buy[n];
        int sell[n];
        buy[0]=-1*prices[0];
        sell[0]=0;
        for(int i=1;i<n;i++)
        {
            if(i>1)
                buy[i]=max(buy[i-1],sell[i-2]-prices[i]);
            else
                buy[i]=max(buy[i-1],-1*prices[i]);
            sell[i]=max(sell[i-1],buy[i-1]+prices[i]);
        }
        return sell[n-1];
    }
};