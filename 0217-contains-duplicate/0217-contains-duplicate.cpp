class Solution {
public:
    // Find if a vector contains a duplicate number
    bool containsDuplicate( vector<int>& rNums )
    {
        std::unordered_set<int> num_set;

        // if it is already in the set return out
        for ( const int & num : rNums )
        {
            if ( num_set.count( num ) )
            {
                return true;
            }
            num_set.insert( num );
        }  
        return false;
    } // end of containsDuplicate
}; // end of Solution class