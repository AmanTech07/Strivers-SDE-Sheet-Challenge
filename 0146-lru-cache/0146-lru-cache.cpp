class LRUCache {
    set<pair<int, int>> s;
    int sz, level = 0;
    map<int, pair<int, int>> m;
public:
    LRUCache(int capacity) {
        sz = capacity;
    }
    
    int get(int key) {
        if(m.count(key)) {
            s.erase({m[key].second, key});
            s.insert({++level, key});
            m[key] = {m[key].first, level};
            return m[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)) {
            auto ele = m[key];
            s.erase({ele.second, key});
            s.insert({++level, key});
            m[key] = {value, level};
        }
        else {
            if(s.size()==sz) {
                auto ele = *s.begin();
                m.erase(ele.second);
                s.erase(ele);
                s.insert({++level, key});
                m[key] = {value, level};
            }
            else {
                s.insert({++level, key});
                m[key] = {value, level};
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */