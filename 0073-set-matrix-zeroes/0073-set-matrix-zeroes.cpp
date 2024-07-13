class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        bool top_row{false};
        bool left_col{false};

        for ( int y = 0; y < matrix.size(); y++ )
        {
            if ( matrix[y][0] == 0 )
            {
                left_col = true;
            }
        }

        for ( int x = 0; x < matrix[0].size(); x++ )
        {
            if ( matrix[0][x] == 0 )
            {
                top_row = true;
            }
        }

        for ( int y = 1; y < matrix.size(); y++ )
        {
            for ( int x = 1; x < matrix[0].size(); x++ )
            {
                if ( matrix[y][x] == 0 )
                {
                    matrix[0][x] = 0;
                    matrix[y][0] = 0;
                }
            }
        }

        for ( int y = 1; y < matrix.size(); y++ )
        {
            if ( matrix[y][0] == 0 )
            {
                for ( int x = 0; x < matrix[0].size(); x++ )
                {
                    matrix[y][x] = 0;
                }
            }
        }

        for ( int x = 1; x < matrix[0].size(); x++ )
        {
            if ( matrix[0][x] == 0 )
            {
                for ( int y = 0; y < matrix.size(); y++ )
                {
                    matrix[y][x] = 0;
                }
            }
        }
        
        if ( left_col )
        {
            for ( int y = 0; y < matrix.size(); y++ )
            {
                matrix[y][0] = 0;
            }
        }
        if ( top_row )
        {
            for ( int x = 0; x < matrix[0].size(); x++ )
            {
                matrix[0][x] = 0;
            }
        }


    }
};