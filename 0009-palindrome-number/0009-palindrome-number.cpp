class Solution {
public:
    bool isPalindrome( int x )
    {
        if ( x < 0 ) return false;

        long long reverse{ 0 };
        long long x_copy{ x };
        while ( x > 0 )
        {
            reverse *= 10;
            reverse += x % 10;
            x /= 10;
        }
        
        return x_copy == reverse;
        
    } // end of isPalindrome
}; // end of Solution class