class Solution {
public:
    // Moores Voting Algorithm
    int majorityElement( vector<int>& nums ) {
        // incremented up and down based on which element is being looked at
        int count = 0;
        // What we think the majority element is atm
        int current_val = 0;
        
        // loop through every element in vector
        for ( const int & num : nums )
        {
            // count is leveled out to zero, next value is assumption
            if ( 0 == count )
            {
                current_val = num;
            }

            // increase count (assume this number is majority)
            if ( current_val == num )
            {
                count++;
            }
            // decrease the count if it is not the current assumption
            else
            {
                count--;
            }
        }
        return current_val;
    } // end of majorityElement

    // Hash map method (First attempt)
    // int majorityElement( vector<int>& nums ) {
    //     unordered_map<int, int> num_map; // map that stores counts of each element
    //     int half_size = nums.size() / 2;

    //     for ( const int & num : nums)
    //     {
    //         // incrememnt each element count
    //         num_map[ num ]++;

    //         // if the count is over half, this is majority element
    //         if ( num_map[ num ] > half_size )
    //         {
    //             return num;
    //         }
    //     }
    //     return 0;
    // } // end of majorityElement
}; // end of Solution class