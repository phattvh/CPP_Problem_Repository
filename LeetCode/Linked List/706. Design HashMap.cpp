//Author: Phat Tran
//All my info: https://phattvh.is-not-a.dev


class MyHashMap {
private:
    static const int bsize = 697;
    vector<vector<pair<int, int>>> table;

    int hash(int key){
        return key % bsize;
    }

    // int data[1000001];

public:
    MyHashMap() {
        table.resize(bsize);
    }
    
    void put(int key, int value) {
        int idx = hash(key);

        for(auto &pair : table[idx]) if (pair.first == key){
            pair.second = value;
            return;
        }

        table[idx].push_back({key, value});
    }
    
    int get(int key) {
        int idx = hash(key);

        for(auto &pair : table[idx]) if (pair.first == key) return pair.second;

        return -1;
    }
    
    void remove(int key) {
        int idx = hash(key);

        for(int i = 0; i < table[idx].size(); i++) if (table[idx][i].first == key){
            table[idx][i] = table[idx].back();
            table[idx].pop_back();
            return;
        }
    }

    // MyHashMap() {
    //     memset(data, -1, sizeof(data));
    // }
    
    // void put(int key, int value) {
    //     data[key] = value;
    // }
    
    // int get(int key) {
    //     return data[key];
    // }
    
    // void remove(int key) {
    //     data[key] = -1;
    // }

};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */

 //cach 1: tuong tu 705, nhung su dung vector<pair<int, int>>
 //cach 2: dung mang don (neu biet truoc phan tu)
