class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> set;
        int n=arr.size();
        for(int i=0;i<n;i++)
            set.insert(arr[i]);
        int count=0;
        for(int i=0;i<n;i++)
            if(set.find(arr[i]+1)!=set.end())
                count++;
        return count;
    }
};