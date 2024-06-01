class Solution {
public:
    bool backspaceCompare( string s, string t )
    {
        // if ( s.length() != t.length() ) return false;
        int s_hashtag{0};
        int t_hashtag{0};
        int s_ind = s.length() - 1;
        int t_ind = t.length() - 1;

        while ( s_ind >= 0 || t_ind >= 0 )
        {
            while ( s_ind >= 0 )
            {
                if ( s[ s_ind ] == '#' ) { s_hashtag++; s_ind--; }
                else if ( s_hashtag > 0 ) { s_hashtag--; s_ind--; }
                else { break; }
            }
            while ( t_ind >= 0 )
            {
                if ( t[ t_ind ] == '#' ) { t_hashtag++; t_ind--; }
                else if ( t_hashtag > 0 ) { t_hashtag--; t_ind--; }
                else { break; }
            }
            if ( ( s_ind >= 0 && t_ind >= 0 ) && s[ s_ind ] != t[ t_ind ] )
            {
                return false;
            }
            if ( ( s_ind >= 0 ) != ( t_ind >= 0 ) )
            {
                return false;
            }
            s_ind--;
            t_ind--;
        }
        return true;
    }
};