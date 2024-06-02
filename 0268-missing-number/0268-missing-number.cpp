class Solution {
public:
    // find what number is missing in inputted vector
    int missingNumber( vector<int>& rNums )
    {
        const int NUM_SIZE = rNums.size();
        int sum{ 0 };
        for ( int ind = 1; ind <= NUM_SIZE; ind++ )
        {
            sum += ind;
        }
        for ( const auto & num : rNums )
        {
            sum -= num;
        }
        return sum;
    } // end of missing number
}; // end of Solution class