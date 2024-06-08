class Solution {
public:
    vector<int> productExceptSelf( vector<int>& nums )
    {
        const int NUM_SIZE = nums.size();
        std::vector<int> left_prods( NUM_SIZE );
        left_prods[ 0 ] = 1;

        for ( int ind = 1; ind < NUM_SIZE; ind++ )
        {
            left_prods[ ind ] = left_prods[ ind - 1 ] * nums[ ind - 1 ];
        }

        int right_prods = 1;
        for ( int ind = NUM_SIZE - 1; ind >= 0; ind-- )
        {
            left_prods[ ind ] *= right_prods;
            right_prods *= nums[ ind ];
        }
        return left_prods;
    } // end of productExceptSelf
}; // end of Solution class