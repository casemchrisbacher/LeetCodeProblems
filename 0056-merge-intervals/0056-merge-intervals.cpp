class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        std::sort( intervals.begin(), intervals.end() );

        std::vector<std::vector<int>> merged = { intervals[0] };

        for ( int i = 0; i < intervals.size(); i++ )
        {
            if ( merged.back()[0] >= intervals[i][0] || merged.back()[1] >= intervals[i][0] )
            {
                merged.back() = { std::min( merged.back()[0], intervals[i][0] ), std::max( merged.back()[1], intervals[i][1] ) };
            }
            else
            {
                merged.push_back( intervals[i] );
            }
        }
        return merged;
    } // end of merge
};