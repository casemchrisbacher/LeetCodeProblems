class Solution {
private:
    void islandRemoval( std::vector<std::vector<char>>& grid, int rowInd, int colInd )
    {
        if ( rowInd < 0 || colInd < 0 || rowInd >= grid.size() || colInd >= grid[0].size() || grid[rowInd][colInd] == '0' ) return;

        grid[rowInd][colInd] = '0';

        islandRemoval( grid, rowInd + 1, colInd );
        islandRemoval( grid, rowInd - 1, colInd );
        islandRemoval( grid, rowInd, colInd + 1 );
        islandRemoval( grid, rowInd, colInd - 1 );
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