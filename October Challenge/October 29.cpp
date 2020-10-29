class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int answer=0;
        int count=1;
        int n=seats.size();
        int i=0;
        while(i<n && seats[i]==0)
        {
            answer++;
            i++;
        }
        for(;i<n;i++)
        {
            if(seats[i]==0)
                count++;
            else
            {
                answer=max(answer,count/2);
                count=1;
            }
        }
        answer=max(answer,count-1);
        return answer;
    }
};