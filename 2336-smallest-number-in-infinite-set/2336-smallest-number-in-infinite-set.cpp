class SmallestInfiniteSet {
public:
    set<int> s;
    SmallestInfiniteSet() {
        for(int i = 1 ; i <= 1000 ; i++){
            s.insert(i);
        }
    }
    
    int popSmallest(){
        if(s.size() > 0){
            auto it = *s.begin();
            s.erase(it);
            return it;
        }
        return -1;
    }
    
    void addBack(int num) {
        if(s.find(num) == s.end())
            s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */