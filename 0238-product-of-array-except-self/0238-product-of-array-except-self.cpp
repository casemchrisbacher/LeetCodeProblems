class Solution {
public:
    // Sum of all integers in an array except itself
    vector<int> productExceptSelf( vector<int>& nums )
    {
        int total_sum{1};   // Init to 1, multiplying so we don't want a zero
        int zero_count{0};  // Counter for how many zeros are in vector

        // Loop through vector, get a product of all of it, excluding zeros
        for ( const auto & num : nums )
        {
            // Multiply running sum if not a zero
            if ( num != 0 )
            {
                total_sum *= num;
            }
            // Mark if we found a zero
            else
            {
                zero_count++;
            }
        }

        // If more than one is zero, the whole vector is going to be zero, just return here
        if ( zero_count > 1 )
        {
            return std::vector<int>( nums.size(), 0 );
        }

        // Loop through again to adjust the vals, 
        for ( auto & num : nums )
        {
            // If 1 zero is present - all numbers are zero except
            // for the index where the zero was originally
            if ( num != 0 )
            {
                if ( zero_count == 1 )
                {
                    num = 0;
                }
                else
                {
                    num = total_sum / num;
                }
            }
            else
            {
                 num = total_sum;
            }
        }
        return nums;
    } // end of productExceptSelf
}; // end of Solution class