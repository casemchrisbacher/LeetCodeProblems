class Solution {
public:
    // Find the largest sum of k numbers, but the other numbers decrement after each selection
    // note: the numbers (happiness) does not decrement past zero
    long long maximumHappinessSum( vector<int>& happiness, int k ) 
    {
        long long max_happy{ 0 };   // output val

        // Sort input vector in descending order (max first)
        std::sort( happiness.begin(), happiness.end(), std::greater<>() );
        
        // ind_val_cnt - index of current element, count of previous elements added
        for ( int ind_val_cnt = 0; ind_val_cnt < k; ind_val_cnt++ )
        {
            happiness[ ind_val_cnt ] -= ind_val_cnt;
            // add it to the max value if it's larger than 0
            if ( happiness[ ind_val_cnt ] > 0 )
            {
                max_happy += happiness[ ind_val_cnt ];
            }
            else
            {
                // Once you find one that is less than zero,
                // the rest will be too. Can break out here.
                break;
            }
        }
        return max_happy;
    } // end of maximumHappinessSum
}; // end of Solution class