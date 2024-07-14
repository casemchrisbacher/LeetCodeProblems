/*
 * // This is the custom function interface.
 * // You should not implement it, or speculate about its implementation
 * class CustomFunction {
 * public:
 *     // Returns f(x, y) for any given positive integers x and y.
 *     // Note that f(x, y) is increasing with respect to both x and y.
 *     // i.e. f(x, y) < f(x + 1, y), f(x, y) < f(x, y + 1)
 *     int f(int x, int y);
 * };
 */

class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z) 
    {        
        int left{1};
        int right{1000};
        std::vector<std::vector<int>> nums;
        
        while ( left <= 1000 && right >= 1 )
        {
            if ( customfunction.f( left, right ) == z)
            {
                nums.push_back({left,right});
            }
            if ( customfunction.f( left, right ) > z )
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        return nums;
    }
};