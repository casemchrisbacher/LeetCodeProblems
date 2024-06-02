class Solution {
public:
    int maxSubArray( std::vector<int>& rNums )
    {
        int max{ INT_MIN };
        int cur_max{ 0 };

        for ( const int & num : rNums )
        {
            cur_max += num;
            max = std::max( max, cur_max );
            cur_max = std::max( 0, cur_max );
        }
        return max;
    }

    // int maxSubArray( std::vector<int>& rNums )
    // {
    //     if ( rNums.size() == 1 ) return rNums[ 0 ];

    //     int max{ rNums[ 0 ] };
    //     int cur_sum{ rNums[ 0 ] };
    //     int left{ 1 };
    //     int right{ 1 };
    //     const int NUM_SIZE = rNums.size();

    //     while ( right < NUM_SIZE )
    //     {
    //         if ( rNums[ right ] > ( cur_sum + rNums[ right ] ) )
    //         { 
    //             cur_sum = rNums[ right ];
    //             left = right;
    //         }
    //         else
    //         {
    //             cur_sum += rNums[ right ];
    //         }
    //         max = std::max( max, cur_sum );
    //         right++;
    //     }
    //     return max;
    // } // end of maxSubArray
}; // end of Solution class