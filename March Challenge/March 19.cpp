class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool seen[rooms.size()];
        memset(seen,false,sizeof(seen));
        seen[0]=true;
        stack<int> st;
        st.push(0);

        while (!st.empty())
        {
            int node=st.top();
            st.pop();
            for (int nei: rooms[node])
                if (!seen[nei])
                {
                    seen[nei]=true;
                    st.push(nei);
                }
        }

        for(bool v: seen)
            if (!v)
                return false;
        return true;
    }
};