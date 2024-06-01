class Solution {
public:
    int longestPalindrome( string s )
    {
        std::unordered_map<char,int> letters;
        int num_in_pal{ 0 };

        // add the letters to map
        for ( const char & letter : s )
        {
            letters[ letter ]++;
        }

        // loop through to count the pairs
        for ( const auto & char_count_pair : letters )
        {
            num_in_pal += char_count_pair.second - ( char_count_pair.second % 2 );
        }
        // if there was a letter left out, the sizes wont be the same
        return num_in_pal + !( num_in_pal == s.length() );
    } // end of longestPalindrome
}; // end of Solution class