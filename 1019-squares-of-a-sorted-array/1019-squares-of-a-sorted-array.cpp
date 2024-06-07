class Solution {
public:
    vector<int> sortedSquares( vector<int>& nums ) 
    {
        const int NUM_SIZE = nums.size();
        int l = 0;
        int r = NUM_SIZE - 1;
        std::vector<int> squares;

        while ( l <= r )
        {
            int left_sq = nums[ l ] * nums[ l ];
            int right_sq = nums[ r ] * nums[ r ];

            if ( right_sq < left_sq )
            {
                squares.push_back( left_sq );
                l++;
            }
            else
            {
                squares.push_back( right_sq );
                r--;
            }
        }
        std::reverse( squares.begin(), squares.end() );
        return squares;
    }
};