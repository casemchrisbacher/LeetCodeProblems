/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    // Standard binary search
    int guessNumber( int high ) 
    {
        int inc_dec{ 0 };   // output of guess function
        int low{ 0 };       // lower bound
        
        while ( low <= high )
        {
            // find the middle point and guess it
            int mid{ low + ( high - low ) / 2 };
            int inc_dec{ guess( mid ) };
            if ( inc_dec == 0 )
            {
                return mid;
            }
            else if ( inc_dec == 1 )
            {
                // Shift to the upper half if it's bigger than guessed
                low = mid + 1;
            }
            else if ( inc_dec == -1 )
            {
                
                high = mid - 1;
            }
        }
        return -1;
    }
};