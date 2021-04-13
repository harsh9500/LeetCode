/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> numbers;
    void generate(vector<NestedInteger> nestedList)
    {
        for(auto v:nestedList)
        {
            if(v.isInteger())
            {
                numbers.push_back(v.getInteger());
            }
            else
            {
                generate(v.getList());
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        generate(nestedList);
        reverse(numbers.begin(),numbers.end());
    }
    
    int next() {
        if(hasNext())
        {
            int val = numbers.back();
            numbers.pop_back();
            return val;
        }
        return -1;
    }
    
    bool hasNext() {
        return numbers.size() == 0 ? false : true;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */