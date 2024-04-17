class Solution {
public:
    void merge( vector<int>& nums1, int m, vector<int>& nums2, int n ) {
        // go through the large vector (nums1) from the top down
        int vect_ind = m + n - 1;   // start with the largest index of nums1
        m--;                        // reuse m as the nums1 index
        n--;                        // reuse n as the nums2 index

        // Only have to loop through nums2.
        // Once it gets past index 0 in nums2, the leftover nums1 numbers are
        // already in place and sorted, so just finish function
        while ( n >= 0 )
        {
            // m >= 0 checks for the [0] edge case (since it's size 0)
            if ( m >= 0 && nums1[ m ] >= nums2[ n ] ) // if/ else to grab bigger value
            {
                nums1[ vect_ind ] = nums1[ m ];
                m--;
            }
            else
            {
                nums1[ vect_ind ] = nums2[ n ];
                n--;
            }
            vect_ind--; // decrement the vector index
        }
    } // end of merge
}; // end of Solution class