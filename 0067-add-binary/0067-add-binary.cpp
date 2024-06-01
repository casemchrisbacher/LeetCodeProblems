class Solution {
    char binaryAddr( bool& carry, char a, char b )
    {
        int ones = ( carry ) + ( a == '1' ) + ( b == '1' );

        switch( ones )
        {
            case 0:
                return '0';
            case 1:
                carry = false;
                return '1';
            case 2:
                carry = true;
                return '0';
            case 3:
                carry = true;
                return '1';
            default:
                break;
        }
        return '?'; // will never get here
    } // end of binaryAddr

public:
    string addBinary( string a, string b )
    {
        std::string sum{""};
        int a_ind = a.length() - 1;
        int b_ind = b.length() - 1;
        bool carry{ false };

        // loop through every index using helper function to add and keep track of carry
        while ( a_ind >= 0 && b_ind >= 0 )
        {
            sum += binaryAddr( carry, a[ a_ind ], b[ b_ind ] );
            a_ind--;
            b_ind--;
        }
        while ( a_ind >= 0 )
        {
            sum += binaryAddr( carry, a[ a_ind ], '0' );
            a_ind--;
        }
        while ( b_ind >= 0 )
        {
            sum += binaryAddr( carry, b[ b_ind ], '0' );
            b_ind--;
        }

        // add leftover carry if needed
        if ( carry ) { sum += '1'; }

        // += adds it in "reverse" so flip it
        reverse( sum.begin(), sum.end() );
        return sum;
    } // end of addBinary 
}; // end of Solution class