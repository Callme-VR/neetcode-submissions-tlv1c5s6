class LRUCache {
private:
    int cap;
    // Stores {key, value} pairs
    std::list<std::pair<int, int>> cacheList; 
    // Maps key to the iterator of the node in cacheList
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> cacheMap;

public:
    // Fixed: Constructor syntax
    LRUCache(int capacity) : cap(capacity) {}

    int get(int key) {
        // If key doesn't exist
        if (cacheMap.find(key) == cacheMap.end()) {
            return -1;
        }
        
        // Move the accessed node to the front (Most Recently Used)
        cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
        return cacheMap[key]->second;
    }

    void put(int key, int value) {
        // If key already exists
        if (cacheMap.find(key) != cacheMap.end()) {
            cacheList.splice(cacheList.begin(), cacheList, cacheMap[key]);
            cacheMap[key]->second = value;
            return;
        }

        // If cache is full, remove the Least Recently Used (back of the list)
        if (cacheList.size() == cap) {
            int lruKey = cacheList.back().first;
            cacheMap.erase(lruKey); // Remove from map
            cacheList.pop_back();   // Remove from list
        }

        // Insert new pair at the front
        cacheList.push_front({key, value});
        cacheMap[key] = cacheList.begin();
    }
};