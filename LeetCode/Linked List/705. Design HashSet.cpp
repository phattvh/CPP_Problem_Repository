class MyHashSet {
private:
    static const int bsize = 1000; 
    vector<vector<int>> table;

    int hash(int key) {
        return key % bsize;
    }

public:
    MyHashSet() {
        table.resize(bsize);
    }
    
    void add(int key) {
        int idx = hash(key);
        if (!ranges::contains(table[idx], key)) table[idx].push_back(key);
    }
    
    void remove(int key) {
        int idx = hash(key);
        auto it = find(table[idx].begin(), table[idx].end(), key);
        if (it != table[idx].end()) table[idx].erase(it);
    }
    
    bool contains(int key) {
        int idx = hash(key);

        return find(table[idx].begin(), table[idx].end(), key) != table[idx].end();
    }

//   vector<bool> bszie;

//   MyHashSet() {
//       bsize.resize(1000001, false);
//   }

//   void add(int key) {
//     bsize[key] = true;
//   }

//   void remove(int key) {
//       bsize[key] = false;
//   }

//   bool contains(int key) {
//       return present[key];
//   }

};


/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

 //phuong phap seperate chaining
