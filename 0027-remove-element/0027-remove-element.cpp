class Solution {
public:
    // Implement remove, leave the vector the same size
    int removeElement( vector<int>& nums, int val ) 
    {
        // Slow moving element, start at element 0
        int slow_ind = 0;
        int nums_size = nums.size();

        for ( int ind = 0; ind < nums_size; ind++ )
        {
            // Check to see if it's not the value we want to remove, else ignore
            if ( nums[ ind ] != val )
            {
                // Slow index only increments when it's not the value
                nums[ slow_ind++ ] = nums[ ind ];
            }
        }
        return slow_ind;
    } // end of removeElement
}; // end of Solution class