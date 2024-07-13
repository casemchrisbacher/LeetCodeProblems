class LRUCache {
private:
    int mSpace{0};
    std::list<int> mKeyList;
    std::unordered_map<int, std::pair<std::list<int>::iterator, int>> mItValMap;
public:
    LRUCache(int capacity) 
    {
        mSpace = capacity;
    }
    void moveToFront( int key )
    {
        mKeyList.erase( mItValMap[key].first );
        mKeyList.push_front(key);
        mItValMap[key].first = mKeyList.begin();
    }

    int get(int key) 
    {
        if ( mItValMap.find(key) == mItValMap.end() ) return -1;
        moveToFront(key);
        return mItValMap[key].second;
    }
    
    void put(int key, int value) 
    {
        if ( mItValMap.find(key) == mItValMap.end() )
        {
            mKeyList.push_front(key);
            mItValMap[key] = { mKeyList.begin(), value };
            mSpace--;
        }
        else
        {
            moveToFront(key);
            mItValMap[key].second = value;
        }

        if ( mSpace < 0 )
        {
            mItValMap.erase( mKeyList.back() );
            mKeyList.pop_back();
            mSpace++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */