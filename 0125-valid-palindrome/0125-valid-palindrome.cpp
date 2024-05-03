class Solution {
public:
    // Two pointers method
    // Left side starts at 0, right side starts at max
    // Shift them closer to each other, comparing along the way
    // End when they are the same or left is bigger than right
    bool isPalindrome( string s ) 
    {
        int left_index = 0;
        int right_index = s.length() - 1;

        while ( left_index <= right_index )
        {
            // Skip all non-alphanumeric inputs
            if ( !std::isalnum( s[ left_index ] ) )
            {
                left_index++;
                continue;
            }
            if ( !std::isalnum( s[ right_index ] ) )
            {
                right_index--;
                continue;
            }
            // Are these matching characters?
            if ( std::tolower( s[ left_index ] ) != std::tolower( s[ right_index ] ) )
            {
                return false;
            }
            else
            {
                // increment them closer together
                left_index++;
                right_index--;
            }
        }
        // parsed entire string, tis a palindrome
        return true;
    } // end of isPalindrome
}; // end of Solution class 