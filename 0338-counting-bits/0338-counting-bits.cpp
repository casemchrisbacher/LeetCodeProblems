class Solution {
public:
    std::vector<int> countBits( int n )
    {
        std::vector<int> bits( n+1 );
        if ( n == 0 ) return bits;

        bits[ 1 ] = 1;

        for ( int ind = 2; ind <= n; ind++ )
        {
            bits[ ind ] = ( ind % 2 ) + bits[ ind / 2 ];
        }
        return bits;
    } // end of countBits
}; // end of Solution class