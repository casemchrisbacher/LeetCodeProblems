class Solution {
public:
    void rotate( vector<int>& nums, int k ) {
        int n = nums.size();
        k = k % n; // Ensure k is within the range [0, n)
        
        // assume k = 2 for example in comments
        // reverse the entire vector 123|45 -> 543|21
        reverse( nums.begin(), nums.end() );

        // reverse beginning 345|21
        reverse( nums.begin(), nums.begin() + k );

        // reverse end 345|12 
        reverse( nums.begin() + k, nums.end() );

        // final result = 34512 -> officially been shifted twice
    } // end of rotate
}; // end of Solution class