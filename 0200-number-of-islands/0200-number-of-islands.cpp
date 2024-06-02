class Solution {
private:
    void islandRemoval( vector<vector<char>>& grid, int row, int col )
    {
        if ( row < 0 || col < 0 || row >= grid.size() || col >= grid[ 0 ].size() )
        {
            return;
        }
        if ( grid[ row ][ col ] == '1' )
        {
            grid[ row ][ col ] = '0';
            islandRemoval( grid, row, col + 1 );
            islandRemoval( grid, row, col - 1 );
            islandRemoval( grid, row - 1, col );
            islandRemoval( grid, row + 1, col );
        }
    } // end of islandRemoval

public:
    int numIslands( vector<vector<char>>& grid )
    {
        const int ROW_SIZE = grid.size();
        const int COL_SIZE = grid[ 0 ].size();
        int island_cnt{0};
        for ( int row_ind = 0; row_ind < ROW_SIZE; row_ind++ )
        {
            for ( int col_ind = 0; col_ind < COL_SIZE; col_ind++ )
            {
                if ( grid[ row_ind ][ col_ind ] == '1' )
                {
                    islandRemoval( grid, row_ind, col_ind );
                    island_cnt++;
                }
            }
        }
        return island_cnt;
    } // end of numIslands
}; // end of Solution class