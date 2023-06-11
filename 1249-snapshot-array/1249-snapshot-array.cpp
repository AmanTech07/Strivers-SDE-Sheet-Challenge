class SnapshotArray {
public:
    vector<map<int, int>> v;
    int snapId;
    SnapshotArray(int length) {
        v.resize(length);
        for(auto &x: v) {
            x[0] = 0;
        }
        snapId=0;
    }
    
    void set(int index, int val) {
        v[index][snapId]=val;
    }
    
    int snap() {
        return snapId++;
    }
    
    int get(int index, int snap_id) {
        auto &x = v[index];
        auto it = x.upper_bound(snap_id);
        return (--it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */