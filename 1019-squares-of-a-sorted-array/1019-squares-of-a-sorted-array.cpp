class Solution {
public:
    vector<int> sortedSquares( vector<int>& nums ) 
    {
        const int NUM_SIZE = nums.size();
        int l = 0;
        int r = NUM_SIZE - 1;
        int top = NUM_SIZE - 1;
        std::vector<int> squares( NUM_SIZE );

        while ( l <= r )
        {
            int left_sq = nums[ l ] * nums[ l ];
            int right_sq = nums[ r ] * nums[ r ];

            if ( right_sq < left_sq )
            {
                squares[ top-- ] = left_sq;
                l++;
            }
            else
            {
                squares[ top-- ] = right_sq;
                r--;
            }
        }
        return squares;
    }
};