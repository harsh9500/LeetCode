class MyCalendar {
public:
    set<pair<int, int>> books;
    MyCalendar() {
        books.clear();
    }
    
    bool book(int start, int end) {
        auto next = books.lower_bound({start, end});
        if (next != books.end() && next->first < end) return false;
        if (next != books.begin() && start < (--next)->second) return false;
        books.insert({ start, end });
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */