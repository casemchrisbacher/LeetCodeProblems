class Solution {
public:
    string longestCommonPrefix( vector<string>& strs )
    {
        std::sort( strs.begin(), strs.end() );
        const int LAST_IND = strs.size() - 1;
        const int LEN = std::min( strs[ 0 ].length(), strs[ LAST_IND ].length() );

        for ( int ind = 0; ind < LEN; ind++ )
        {
            if ( strs[ 0 ][ ind ] != strs[ LAST_IND ][ ind ] )
            {
                return strs[ 0 ].substr( 0, ind );
            }
        }
        return strs[ 0 ];
    }
};