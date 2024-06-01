class Solution {
public:
    // Count 1 bits
    int hammingWeight( int n )
    {
        int bits{ 0 };

        while ( n > 0 )
        {
            bits += ( n % 2 );
            n /= 2;
        }
        return bits;
    } // end of hammingWeight
}; // end of Solution class