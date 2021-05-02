class Solution {
public:
    static bool comp(const vector<int>& v1, const vector<int>& v2)
    {
        if(v1[1]<v2[1])
            return true;
        if(v1[1]==v2[1])
        {
            if(v1[0]<v2[0])
                return true;
        }
        return false;
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),comp);
        int time=0, count=0;
        for (int i=0; i<courses.size();i++)
        {
            if (time+courses[i][0]<=courses[i][1])
            {
                time+=courses[i][0];
                courses[count++]=courses[i];
            }
            else
            {
                int max_i = i;
                for (int j=0; j<count; j++)
                {
                    if (courses[j][0]>courses[max_i][0])
                        max_i=j;
                }
                if (courses[max_i][0] > courses[i][0])
                {
                    time+=courses[i][0]-courses[max_i][0];
                    courses[max_i] = courses[i];
                }
            }
        }
        return count;
    }
};