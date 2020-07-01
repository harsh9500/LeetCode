class Solution {
public:
    int arrangeCoins(int n) {
        // int answer=0,i=1;
        // while(n>0)
        // {
        //     if(n>=i)
        //     {
        //         answer++;
        //         n-=i;
        //         i++;
        //     }
        //     else
        //         break;
        // }
        // return answer;
        
        long int low=0,high=n,mid,steps;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            steps=mid*(mid+1)/2;
            if(steps==n)
                return mid;
            if(steps<n)
                low=mid+1;
            else
                high=mid-1;
        }
        return high;
    }
};