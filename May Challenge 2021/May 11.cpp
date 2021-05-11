class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int total_pts = accumulate(cardPoints.begin(),cardPoints.end(),0);
        int n = cardPoints.size();
        int size = n-k;
        
        int minSubArraySum = INT_MAX;
        int j=0, curr=0;
        
        for(int i=0;i<n;i++)
        {
            int v=cardPoints[i];
            curr+=v;
            if(i-j+1>size)
            {
                curr-=cardPoints[j];
                j+=1;
            }
            if(i-j+1==size)  
                minSubArraySum = min(minSubArraySum, curr);

        }
            
        return total_pts-minSubArraySum;
    }
};