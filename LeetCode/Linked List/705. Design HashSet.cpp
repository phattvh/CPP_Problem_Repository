//Author: Phat Tran
//All my info: https://phattvh.is-not-a.dev


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
        for (int x : table[idx]) if (x == key) return;
            
        table[idx].push_back(key);
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



//1. SEPARATE CHAINING

// Y tuong:
// Gom cac phan tu vao cac bucket
// Khi co xung dot (nhieu so cung ma bam), chung se duoc luu chung vao mot xo.

// Co che:
// 1. Dung phep chia lay du (key % bsize) de quy doi key thanh chi so tu 0 den bsize - 1.
// 2. Add: Tinh chi so idx. Kiem tra xem key da co trong xo table[idx] chua. Neu chua co thi them vao cuoi.
// 3. Remove: Tinh idx, tim vi tri cua key trong xo. Neu co thi xoa di.
// 4. Contains: Tinh idx, tim trong xo table[idx] xem key ton tai khong.


//2: DIRECT ADDRESSING 

// Y tuong: Tan dung gioi han de bai (key <= 10^6) de anh xa truc tiep moi key vao mot o nho, khong can ham bam.

// Co che:
// 1. Dung mang vector<bool> co 1000001 phan tu, ban dau toan bo la false.
// 2. Add: Danh dau phan tu da xuat hien bang cach gan bsize[key] = true.
// 3. Remove: Danh dau phan tu bi xoa bang cach gan bsize[key] = false.
// 4. Contains: Kiem tra gia tri boolean tai o bsize[key].
