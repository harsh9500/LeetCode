class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum = 0;
        int n = target.size();
        priority_queue<int> pq(target.begin(),target.end());
        for(int ele:target)
            sum+=ele;
        int a;
        while(true)
        {
            a = pq.top();
            pq.pop();
            sum-=a;
            if(a == 1 || sum == 1)
                return true;
            if(a < sum || sum == 0 || a % sum == 0)
                return false;
            a%=sum;
            sum+=a;
            pq.push(a);
        }
        
    }
};