class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> topologicalOrder(numCourses,0);
        vector<int> indegree(numCourses,0);
        unordered_map<int,vector<int>> adjacencyList;
        int n=prerequisites.size();
        for(int i=0;i<n;i++)
        {
            int source=prerequisites[i][1];
            int destination=prerequisites[i][0];
            if(adjacencyList.find(source)==adjacencyList.end())
            {
                vector<int> temp;
                temp.push_back(destination);
                adjacencyList[source]=temp;
            }
            else
            {
                adjacencyList[source].push_back(destination);
            }
            indegree[destination]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++)
        {
            if(indegree[i]==0)
                q.push(i);
        }
        int iter=0;
        while(!q.empty())
        {
            int current=q.front();
            q.pop();
            topologicalOrder[iter]=current;
            iter++;
            if(adjacencyList.find(current)!=adjacencyList.end())
            {
                for(int i=0;i<adjacencyList[current].size();i++)
                {
                    int neighbour=adjacencyList[current][i];
                    indegree[neighbour]--;
                    if(indegree[neighbour]==0)
                        q.push(neighbour);
                }
            }
        }
        if(iter==numCourses)
            return topologicalOrder;
        else
            return vector<int> (0,0);
    }
};