class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        std::unordered_map<int, int> nums_map; // key: number, value: index (of value in nums vector)
        const int SIZE_NUMS = nums.size();

        for ( int i = 0; i < SIZE_NUMS; i++ )
        {
            // x + y = target
            // assume current value is x, AKA x = nums[i]
            // rearrange function to: y = target - x
            // if we have previously stored that value (y) in nums_map, we have a pair
            // the problem asks for indexes, which is the value stored at y and current i
            if ( nums_map.count( target - nums[i] ) )
            {
                return { nums_map[ target - nums[i] ], i };
            }
            nums_map[ nums[i] ] = i; // else: add it to the map and keep on lookin
        }
        return {};
    } // end of twoSum
};