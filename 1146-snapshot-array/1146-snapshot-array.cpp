class SnapshotArray {
public:
    map<int,map<int,int>> snapshot;
    int current_snap_id;
    SnapshotArray(int length) {
        current_snap_id = 0;
    }
    
    void set(int index, int val) {
        snapshot[index][current_snap_id] = val;
    }
    
    int snap() {
        current_snap_id++;
        return current_snap_id - 1;
    }
    
    int get(int index, int snap_id) {
        if(snapshot[index].size() == 0) return 0;
        auto it = snapshot[index].upper_bound(snap_id);
        if (it == snapshot[index].begin()) return 0;
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */