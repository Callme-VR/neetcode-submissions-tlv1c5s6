class LFUCache {
public:
    int cap, minFreq;

    unordered_map<int, pair<int,int>> keyValFreq; 
    // key -> {value, freq}

    unordered_map<int, list<int>> freqList; 
    // freq -> list of keys

    unordered_map<int, list<int>::iterator> keyIter;
    // key -> iterator in freq list

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(int key) {
        int freq = keyValFreq[key].second;

        // remove from old freq list
        freqList[freq].erase(keyIter[key]);

        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // increase freq
        keyValFreq[key].second++;

        freqList[freq + 1].push_front(key);
        keyIter[key] = freqList[freq + 1].begin();
    }

    int get(int key) {
        if (keyValFreq.find(key) == keyValFreq.end()) return -1;

        updateFreq(key);
        return keyValFreq[key].first;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyValFreq.find(key) != keyValFreq.end()) {
            keyValFreq[key].first = value;
            updateFreq(key);
            return;
        }

        if (keyValFreq.size() == cap) {
            int keyToRemove = freqList[minFreq].back();

            freqList[minFreq].pop_back();
            if (freqList[minFreq].empty()) {
                freqList.erase(minFreq);
            }

            keyValFreq.erase(keyToRemove);
            keyIter.erase(keyToRemove);
        }

        keyValFreq[key] = {value, 1};
        freqList[1].push_front(key);
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }
};