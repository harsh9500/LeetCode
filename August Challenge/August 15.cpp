class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n==0)
            return 0;
        auto comp=[](const vector<int>& i1, const vector<int>& i2){ return i1[1] < i2[1]; };
        sort(intervals.begin(),intervals.end(),comp);
        int end=intervals[0][1];
        int c=1;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0]>=end)
            {
                end=intervals[i][1];
                c++;
            }

        }
        return n-c;

//         sort(intervals.begin(),intervals.end());
//         int answer=0,index=0;
//         for(int i=1;i<n;i++)
//         {
//             if(intervals[i][0]<intervals[index][1])
//             {
//                 answer++;
//                 if(intervals[i][1]<intervals[index][1])
//                     index=i;
//             }
//             else
//             {
//                 index=i;
//             }
            
//         }
//         return answer;
    }
};