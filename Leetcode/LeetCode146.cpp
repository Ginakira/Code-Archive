// LeetCode 146 LRU缓存机制
#include <unordered_map>
using namespace std;

class CacheNode {
   public:
    friend class LRUCache;

   private:
    CacheNode(int k, int v) : key(k), val(v), next(nullptr), prev(nullptr) {}
    int key, val;
    CacheNode *next, *prev;
};

class LRUCache {
   private:
    unordered_map<int, CacheNode *> node_map;
    CacheNode *head;
    int size;
    int capacity;

   public:
    LRUCache(int cap) : size(0), capacity(cap) {
        head = new CacheNode(-1, -1);
        head->next = head;
        head->prev = head;
    }

    void moveToTail(CacheNode *node) {
        if (node == nullptr) return;
        if (node->next != nullptr && node->prev != nullptr) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }
        node->prev = head->prev;
        node->next = head;
        head->prev->next = node;
        head->prev = node;
    }

    void deleteOldestNode() {
        CacheNode *node = head->next;
        head->next = node->next;
        node->next->prev = head;
        --size;
        node_map.erase(node->key);
        delete node;
    }

    int get(int key) {
        if (!node_map.count(key)) {
            return -1;
        }
        CacheNode *node = node_map[key];
        moveToTail(node);
        return node->val;
    }

    void put(int key, int value) {
        if (size == capacity && !node_map.count(key)) {
            deleteOldestNode();
        }
        CacheNode *node;
        if (node_map.count(key)) {
            node = node_map[key];
            node->val = value;
        } else {
            node = new CacheNode(key, value);
            node_map[key] = node;
            ++size;
        }
        moveToTail(node);
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */