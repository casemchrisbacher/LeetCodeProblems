class Solution {
public:
    std::vector<int> countBits( int n )
    {
        std::vector<int> bits( n+1, 0 );

        while ( n > 0 )
        {
            if ( bits[ n ] != 0 )
            {
                n--;
                continue;
            }

            int temp{ n };
            int bit_cnt{ 0 };
            while ( temp > 0 )
            {
                if ( temp % 2 == 1 ) bit_cnt++;
                temp /= 2;
            }
            bits[ n ] = bit_cnt;
            n--;
        }
        return bits;
    }
};