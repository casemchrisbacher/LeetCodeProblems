class TimeMap {
private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> map;
public:
    TimeMap() {
        
    }
    
    void set( string key, string value, int timestamp ) 
    {
        map[ key ].push_back( { timestamp, value } );
    } // end of set
    
    string get( string key, int timestamp ) 
    {
        int l{ 0 };
        int r = map[ key ].size() - 1;
        string closest;

        while ( l <= r )
        {
            int mid = ( l + r ) / 2;
            if ( map[ key ][ mid ].first == timestamp )
            {
                return map[ key ][ mid ].second;
            }
            if ( map[ key ][ mid ].first < timestamp )
            {
                closest = map[ key ][ mid ].second;
                l = mid + 1;
            }
            else if ( map[ key ][ mid ].first > timestamp )
            {
                r = mid - 1;
            }
        }
        return closest;
    } // end of get
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */