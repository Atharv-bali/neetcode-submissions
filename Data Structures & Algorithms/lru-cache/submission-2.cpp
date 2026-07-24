class LRUCache {
public:
    int cap;
    deque<pair<int,int>> dq;
    unordered_map<int,int> mpp;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        int i=0;
        for(auto &it:dq) {
            if(it.first == key) {
                dq.erase(dq.begin()+i);
                break;
            } 
            i++;
        }
        if(mpp.find(key)==mpp.end())
            return -1;
        dq.push_back({key,mpp[key]});
        return mpp[key];
    }
    
    void put(int key, int value) {
        if(mpp.find(key)==mpp.end()) {
            if(dq.size()>=cap) {
                mpp.erase(dq.front().first);
                dq.pop_front();
            }
            dq.push_back({key,value});
            mpp[key] = value;
        }
        else {
            int i = 0;
            for(auto &it:dq) {
                if(it.first == key) {
                    dq.erase(dq.begin()+i);
                    break;
                }
                i++;
            }
            dq.push_back({key,value});
            mpp[key] = value;
        }
    }
};
