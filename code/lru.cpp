#include "base.h"

class LRUCache {
private:
    struct CacheNode {
        int key;
        int val;
        CacheNode(int k, int v) : key(k), val(v) {}
    };
    
    int capacity;
    list<CacheNode> cacheList;
    unordered_map<int, list<CacheNode>::iterator> cacheMap;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) return -1;
        
        cacheList.splice(cacheList.begin(), cacheList, it->second);
        cacheMap[key] = cacheList.begin();
        
        return cacheList.begin()->val;
    }
    
    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) {
            if (capacity == cacheList.size()) {
                cacheMap.erase(cacheList.back().key);//此处特别容易出错
                cacheList.pop_back();
            }
            cacheList.insert(cacheList.begin(), CacheNode (key, value));
            cacheMap[key] = cacheList.begin();
        }
        else {
            it->second->val = value;
            cacheList.splice(cacheList.begin(), cacheList, it->second);
            cacheMap[key] = cacheList.begin();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main()
{
	return 0;
}
