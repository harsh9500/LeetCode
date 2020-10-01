class RecentCounter {
public:
    list<int> window;
    RecentCounter() {
        window.clear();
    }
    
    int ping(int t) {
        window.push_back(t);
        while (window.size()>0) {
            if (*window.begin()<t-3000)
                window.pop_front();
            else
                break;
        }
        return window.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */