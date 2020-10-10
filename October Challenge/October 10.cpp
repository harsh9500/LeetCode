// class Solution {
// public:
//     int findMinArrowShots(vector<vector<int>>& points) {
//         vector<vector<int>> answer;
//         sort(points.begin(),points.end());
//         if(points.size()==0)
//             return 0;
//         vector<int> temp=points[0];
//         for(auto interval:points)
//         {
//             if(interval[0]<=temp[1])
//             {
//                 temp[1]=min(temp[1],interval[1]);
//             }
//             else
//             {
//                 answer.push_back(temp);
//                 temp=interval;
//             }
//         }
//         answer.push_back(temp);
//         return answer.size();
//     }
// };

class Solution {
public:
    static bool comp(const vector<int> a, const vector<int> b)
    {
        if(a[1]<=b[1])
            return true;
        return false;
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0)
            return 0;
        sort(points.begin(),points.end(),comp);
        int count=1;
        int arrow=points[0][1];
        for(int i=1;i<n;i++)
        {
            if(arrow>=points[i][0])
                continue;
            count++;
            arrow=points[i][1];
        }
        return count;
    }
};