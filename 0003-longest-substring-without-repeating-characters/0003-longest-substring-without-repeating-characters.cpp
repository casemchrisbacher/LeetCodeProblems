class Solution {
public:
    int lengthOfLongestSubstring( string s )
    {
        int slow{0};
        int max{0};
        const int S_LEN = s.size();
        std::vector<int> letter_cnt( 128, 0 );

        for ( int ind = 0; ind < S_LEN; ind++ )
        {
            letter_cnt[ s[ ind ] ]++;
        
            while ( letter_cnt[ s[ ind ] ] > 1 )
            {
                letter_cnt[ s[ slow ] ]--;
                slow++;
            }

            max = std::max( ind - slow + 1, max );
        }
        return max;
        
    }
};