class Solution {
public:
    vector<int> twoSum( vector<int>& nums, int target ) 
    {
        // map: value, index
        unordered_map<int,int> val_index_map;
        int input_count = nums.size();

        // Loop through index
        for( int index = 0; index < input_count; index++ )
        {
            // The pair value of the one at the curent index
            int complement = target - nums[ index ];

            // check if anything has been added at that spot
            if ( val_index_map.count( complement ) )
            {
                // max ONE solution
                return { val_index_map[ complement ], index };
            }
            val_index_map[ nums[ index ] ] = index;
        }
        return {};  // Should never hit here - every input has exactly one solution
    } // end of twoSum
}; // end of Solution class