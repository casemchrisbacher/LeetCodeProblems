class Solution {
public:
    int largestAltitude( vector<int>& gain )
    {
        int cur_alt{0};
        int max{0};

        for ( const auto& change : gain )
        {
            cur_alt += change;
            if ( cur_alt > max )
            {
                max = cur_alt;
            }
        }
        return max;
    }
};