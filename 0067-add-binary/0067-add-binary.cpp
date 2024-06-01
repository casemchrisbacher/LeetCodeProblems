class Solution {
public:
    string addBinary( string a, string b )
    {
        std::string sum{""};
        int a_ind = a.length() - 1;
        int b_ind = b.length() - 1;
        bool carry{ false };

        while ( a_ind >= 0 && b_ind >= 0 )
        {
            if ( carry )
            {
                if ( a[ a_ind ] == '1' && b[ b_ind ] == '1' )
                {
                    sum += '1';
                }
                else if ( a[ a_ind ] == '1' || b[ b_ind ] == '1' )
                {
                    sum += '0';
                }
                else 
                {
                    sum += '1';
                    carry = false;
                }
            }
            else
            {
                if ( a[ a_ind ] == '1' && b[ b_ind ] == '1' )
                {
                    sum += '0';
                    carry = true;
                }
                else if ( a[ a_ind ] == '1' || b[ b_ind ] == '1' )
                {
                    sum += '1';
                }
                else 
                {
                    sum += '0';
                }
            }
            a_ind--;
            b_ind--;
        }
        while ( a_ind >= 0 )
        {
            if ( carry )
            {
                if ( a[ a_ind ] == '1' )
                {
                    sum += '0';
                }
                else 
                {
                    sum += '1';
                    carry = false;
                }
            }
            else
            {
                if ( a[ a_ind ] == '1' )
                {
                    sum += '1';
                }
                else 
                {
                    sum += '0';
                }
            }
            a_ind--;
        }
        while ( b_ind >= 0 )
        {
            if ( carry )
            {
                if ( b[ b_ind ] == '1' )
                {
                    sum += '0';
                }
                else 
                {
                    sum += '1';
                    carry = false;
                }
            }
            else
            {
                if ( b[ b_ind ] == '1' )
                {
                    sum += '1';
                }
                else 
                {
                    sum += '0';
                }
            }
            b_ind--;
        }

        if ( carry ) { sum += '1'; }

        reverse( sum.begin(), sum.end() );
        return sum;
    } // end of addBinary 
}; // end of Solution class