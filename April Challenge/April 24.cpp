class LRUCache {
public:
    unordered_map<int, pair<int,list<int>::iterator> > map;
    list<int> dq;
    int size;
    LRUCache(int capacity) {
        size=capacity;
    }
    
    int get(int key) {
        if(map.find(key)==map.end())
            return -1;
        auto it=map[key];
        int value=it.first;
        auto iter=it.second;
        map.erase(key);
        dq.erase(iter);
        dq.push_front(key);
        map[key]=make_pair(value,dq.begin());
        return value;
    }
    
    void put(int key, int value) {
        if(map.find(key)==map.end())
        {
            if(dq.size()==size)
            {
                int last=dq.back();
                dq.pop_back();
                map.erase(last);
            }
        }
        else
        {
            auto it=map[key];
            dq.erase(it.second);
        }
        dq.push_front(key);
        map[key]=make_pair(value,dq.begin());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */