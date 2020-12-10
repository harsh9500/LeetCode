class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n=arr.size();
        if(n<3)
            return false;
        int curr=arr[0];
        int i=1;
        while(arr[i]>curr)
        {
            curr=arr[i];
            i++;
            if(i==n)
                return false;
        }
        if(i==1)
            return false;
        while(i<n)
        {
            if(arr[i]>=curr)
                return false;
            curr=arr[i];
            i++;
        }
        return true;
    }
};