class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int,int> nums_map; // key: number, value: index
        const int NUM_SIZE = nums.size();

        for ( int i = 0; i < NUM_SIZE; i++ )
        {
            if ( nums_map.count( target - nums[i] ) )
            {
                return { nums_map[ target - nums[i] ], i };
            }
            nums_map[ nums[i] ] = i;
        }
        return {};
    } // end of twoSum
};