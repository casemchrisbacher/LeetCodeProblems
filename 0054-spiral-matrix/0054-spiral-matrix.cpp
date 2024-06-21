class Solution {
public:
    vector<int> spiralOrder( vector<vector<int>>& matrix ) 
    {
        int left{ 0 };
        int top{ 0 };
        int right = matrix[ 0 ].size() - 1;
        int bottom = matrix.size() - 1;
        std::vector<int> unraveled;

        while( left <= right && top <= bottom )
        {
            for ( int go_right = left; go_right <= right; go_right++ )
            {
                unraveled.push_back( matrix[ top ][ go_right ] );
            }
            top++;
            for ( int go_down = top; go_down <= bottom; go_down++ )
            {
                unraveled.push_back( matrix[ go_down ][ right ] );
            }
            right--;

            if ( top > bottom ) break;
            for ( int go_left = right; go_left >= left; go_left-- )
            {
                unraveled.push_back( matrix[ bottom ][ go_left ] );
            }
            bottom--;

            if ( left > right ) break;
            for ( int go_up = bottom; go_up >= top; go_up-- )
            {
                unraveled.push_back( matrix[ go_up ][ left ] );
            }
            left++;
        }
        return unraveled;
    }
};