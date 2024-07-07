class Solution {
public:
    int lengthOfLongestSubstring( string s )
    {
       int slow{0};
       int max{0};
       const int S_LEN = s.length();

       std::set<char> letters_in_substr;

        for ( int fast = 0; fast < S_LEN; fast++ )
        {
            while ( letters_in_substr.count( s[ fast ] ) )
            {
                letters_in_substr.erase( s[slow ] );
                slow++;
            }
            letters_in_substr.insert( s[ fast ] );
            max = std::max( max, fast - slow + 1 );

        }
        return max;
    } // end of lengthOfLongestSubstring
}; // end of Solution class