class Solution {
public:
    void moveZeroes( std::vector<int>& rNums )
    {
        int slow_ind{ 0 };
        int zeros{ 0 };
        const int NUM_SIZE = rNums.size();
        for ( int ind = 0; ind < NUM_SIZE; ind++ )
        {
            if ( rNums[ ind ] != 0 )
            {
                rNums[ slow_ind++ ] = rNums[ ind ];
            }
        }
        while ( slow_ind < NUM_SIZE )
        {
            rNums[ slow_ind++ ] = 0;
        }
    } // end of moveZeroes
}; // end of Solution class