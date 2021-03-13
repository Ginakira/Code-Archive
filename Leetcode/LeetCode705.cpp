// LeetCode 705 设计哈希集合
#include <bitset>
#include <list>
#include <vector>
using namespace std;

// 链地址法
class MyHashSet {
   private:
    vector<list<int>> data;
    static const int base = 648;
    static int hash(int key) { return key % base; }

   public:
    /** Initialize your data structure here. */
    MyHashSet() : data(base) {}

    void add(int key) {
        int key_hash = hash(key);
        for (auto k : data[key_hash]) {
            if (k == key) return;
        }
        data[key_hash].emplace_back(key);
    }

    void remove(int key) {
        int key_hash = hash(key);
        for (auto it = data[key_hash].begin(); it != data[key_hash].end();
             ++it) {
            if ((*it) == key) {
                data[key_hash].erase(it);
                break;
            }
        }
    }

    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        int key_hash = hash(key);
        for (auto k : data[key_hash]) {
            if (k == key) return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */

// bitset（投机取巧）
class MyHashSet {
   private:
    bitset<1000001> data;

   public:
    /** Initialize your data structure here. */
    MyHashSet() {}

    void add(int key) { data.set(key); }

    void remove(int key) { data.reset(key); }

    /** Returns true if this set contains the specified element */
    bool contains(int key) { return data.test(key); }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */