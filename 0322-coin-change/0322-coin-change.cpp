class Solution {
public:
    int coinChange( vector<int>& coins, int amount )
    {
        std::vector<int>num_coins( amount + 1, amount + 1 );
        num_coins[ 0 ] = 0;

        
        for ( int ind = 1; ind <= amount; ind++ )
        {
            for ( const auto & coin : coins )
            {
                if ( ind - coin >= 0)
                    num_coins[ ind ] = std::min( num_coins[ ind ], num_coins[ ind - coin ] + 1 );
            }
        }
        if ( num_coins[ amount ] == amount + 1 ) return -1;
        return num_coins[ amount ];

    }
};