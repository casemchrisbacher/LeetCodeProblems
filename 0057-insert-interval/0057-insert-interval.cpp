class Solution {
public:
    vector<vector<int>> insert( vector<vector<int>>& intervals, vector<int>& newInterval )
    {
        vector<vector<int>> merged_interval;
        const int INTERV_SIZE = intervals.size();
        int ind{0};

        while ( ind < INTERV_SIZE && newInterval[ 0 ] > intervals[ ind ][ 1 ] )
        {
            merged_interval.push_back( intervals[ ind ] );
            ind++;
        }
        while ( ind < INTERV_SIZE && newInterval[ 1 ] >= intervals[ ind ][ 0 ] )
        {
            newInterval[ 0 ] = std::min( newInterval[ 0 ], intervals[ ind ][ 0 ] );
            newInterval[ 1 ] = std::max( newInterval[ 1 ], intervals[ ind ][ 1 ] );
            ind++;
        }
        merged_interval.push_back( newInterval );
        while ( ind < INTERV_SIZE )
        {
            merged_interval.push_back( intervals[ ind ] );
            ind++;
        }
        
        return merged_interval;
        
    } // end of insert
}; // end of Solution class