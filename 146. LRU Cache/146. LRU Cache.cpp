#include <iostream>
#include <unordered_map>
using namespace std;

class LRUList {
public:
    struct node {
        inline node(node* prev, int val, node* next) : val(val), prev(prev), next(next) {} // for emplace mid node in list 
        int val;
        node* prev;
        node* next;
    };
    friend class LRUCache;

    node* front_node;   // heaad of list
    node* back_node;    // tail of list

    inline LRUList() : front_node(nullptr), back_node(nullptr) {}

    inline void push_front(int val) {
        if (front_node == nullptr) {    // node is first in list
            back_node = front_node = new node(nullptr, val, nullptr);
        }
        else {  // node is not first
            front_node->prev = new node(nullptr, val, front_node);
            front_node = front_node->prev;
        }
    }

    inline void pop_back_and_emplace_front(int value) {
        if (back_node == front_node) {  // if front == back
            front_node->val = value;
            return;
        }
        back_node = back_node->prev;
        back_node->next->prev = nullptr;
        back_node->next->val = value;
        back_node->next->next = front_node;
        front_node->prev = back_node->next;
        front_node = back_node->next;
        back_node->next = nullptr;
    }

    inline void replace_to_front_not_first(node* ptr) {
        if (ptr == back_node) { // node is tail (but not first)
            back_node = ptr->prev;
            ptr->prev->next = nullptr;
        }
        else {  // just not first (and not tail)
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
        }

        ptr->prev = nullptr;
        ptr->next = front_node;
        front_node->prev = ptr;
        front_node = ptr;
    }
};

class LRUCache {
public:
    LRUCache(int capacity) : max_capacity(capacity), size(0) {
        data.rehash(capacity);
    }

    inline int get(int key) {  // O(1)
        auto it = data.find(key); // O(1) operation
        if (it == data.end()) {
            return -1;  // (key not found)
        }

        // key found => move to top
        if (it->second.ptr != usage_rating.front_node) {    // if not already on the top
            usage_rating.replace_to_front_not_first(it->second.ptr); // O(1)
        }

        return it->second.value;
    }

    inline void put(int key, int value) {  // O(1)
        auto it = data.find(key);
        if (it == data.end()) { // key is not exists => add
            if (size < max_capacity) {  // just add (without evict other node)
                ++size;
                usage_rating.push_front(key);
            }
            else {  // need to evict the worst (by popularity) node
                data.erase(usage_rating.back_node->val);
                usage_rating.pop_back_and_emplace_front(key);
            }
            data.emplace(key, map_node(value, usage_rating.front_node));
        }
        else {  // key already exists in map => just update a value + push to top rating
            it->second.value = value;
            if (it->second.ptr != usage_rating.front_node) {    // if key not already on the top 
                usage_rating.replace_to_front_not_first(it->second.ptr);    // O(1)
            }
        }
    }
private:
    struct map_node {
        map_node(int value, LRUList::node* rating_ptr) : value(value), ptr(rating_ptr) {}
        int value;
        LRUList::node* ptr;
    };
    unordered_map<int, map_node> data;
    LRUList usage_rating;
    const int max_capacity; // maximum of capacity
    int size;   // count of nodes in data (now)
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {    // for tests
    LRUCache lru_cache(3);

    lru_cache.put(1, 1);
    lru_cache.put(2, 2);
    lru_cache.put(3, 3);

    cout << lru_cache.get(1) << ' ' << lru_cache.get(2) << ' ' << lru_cache.get(3) << endl;

    lru_cache.put(3, 0);
    lru_cache.put(4, 4);

    cout << lru_cache.get(1) << ' ' << lru_cache.get(2) << ' ' << lru_cache.get(3) << ' ' << lru_cache.get(4);

}