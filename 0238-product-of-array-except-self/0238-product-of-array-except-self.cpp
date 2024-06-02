class Solution {
public:
    vector<int> productExceptSelf( vector<int>& nums )
    {
        const int NUM_SIZE = nums.size();
        std::vector<int> products( NUM_SIZE, 1 );

        for ( int ind = 1; ind < NUM_SIZE; ind++ )
        {
            products[ ind ] = nums[ ind - 1 ] * products[ ind - 1 ];
        }
        int right{1};

        for ( int ind = NUM_SIZE - 1; ind >= 0; ind-- )
        {
            products[ ind ] *= right;
            right = right * nums[ ind ];
        }   
        return products;

    } // end of productExceptSelf
}; // end of Solution class