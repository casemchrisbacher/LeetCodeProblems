class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        std::sort( intervals.begin(), intervals.end() );
        std::vector<int> cur = intervals[ 0 ];
        std::vector<std::vector<int>> merged;
        for ( const auto & range : intervals )
        {
            if ( range[ 0 ] <= cur[ 1 ] )
            {
                cur[ 1 ] = std::max( range[ 1 ], cur[ 1 ] );
            }
            else
            {
                merged.push_back( cur );
                cur = range;
            }
        }
        merged.push_back( cur );
        return merged;
    }
};