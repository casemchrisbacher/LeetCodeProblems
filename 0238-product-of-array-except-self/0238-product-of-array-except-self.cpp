class Solution {
public:
    vector<int> productExceptSelf( vector<int>& nums )
    {
        int num_zeros{0};
        int product{1};

        for ( const int & num : nums )
        {
            if ( num == 0 )
            {
                num_zeros++;
            }
            else
            {
                product *= num;
            }
        }
        
        if ( num_zeros == 0 )
        {
            for( int & num : nums )
            {
                num = product / num;
            }
            return nums;
        }
        else if ( num_zeros == 1 )
        {
            for( int & num : nums )
            {
                if ( num == 0 )
                {
                    num = product;
                }
                else
                {
                    num = 0;
                }
            }
            return nums;
        }
        return vector<int>( nums.size(), 0 );
    } // end of productExceptSelf
}; // end of Solution class