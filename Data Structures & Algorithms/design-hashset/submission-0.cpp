class MyHashSet {
public:
    vector<bool> store;
    MyHashSet() {
        for(int i = 0; i <= 1000000; i++){
            store.push_back(false);
        }
    }
    
    void add(int key) {
        store[key]=true;
    }
    
    void remove(int key) {
        store[key]=false;
    }
    
    bool contains(int key) {
        return store[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */