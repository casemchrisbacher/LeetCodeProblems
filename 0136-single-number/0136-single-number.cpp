class Solution {
public:
    int singleNumber( vector<int>& nums )
    {
        int single_num{0};
        for ( const int & num : nums )
        {
            single_num ^= num;
        }
        return single_num;
    } // end of singleNumber
}; // end of Solution class