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
            // use the ASCII as integers for indexing
            letter_cnt[ s[ ind ] ]++;

            // if there is more than one of that letter in vector
            // pop letters off the back of the vector until there is but one
            while ( letter_cnt[ s[ ind ] ] > 1 ) 
            {
                letter_cnt[ s[ slow ] ]--;
                slow++;
            }
            max = std::max( ind - slow + 1, max );
        }
        return max;
    } // end of lengthOfLongestSubstring
}; // end of Solution class