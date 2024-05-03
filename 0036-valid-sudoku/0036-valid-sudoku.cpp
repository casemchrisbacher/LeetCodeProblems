class Solution {
public:
    // *******************************************************************************************************
    // 2D Vector of Booleans Solution
    // *******************************************************************************************************
    bool isValidSudoku( vector<vector<char>>& board ) 
    {
        // Get the board size for value calculations (Will always be 9)
        const size_t BOARD_DIM = board.size();

        // booleans for each row, col, and square to determine if that number has been seen yet
        std::vector<std::vector<bool>> in_row( BOARD_DIM, std::vector<bool>( BOARD_DIM, false ) );
        std::vector<std::vector<bool>> in_column( BOARD_DIM, std::vector<bool>( BOARD_DIM, false ) );
        std::vector<std::vector<bool>> in_square( BOARD_DIM, std::vector<bool>( BOARD_DIM, false ) );

        // loop through entire grid O(m*n), for this problem O(9*9) = O(81) = O(1), but O(m*n) for all sizes
        for ( size_t row_ind = 0; row_ind < BOARD_DIM; row_ind++ )
        {
            for ( size_t col_ind = 0; col_ind < BOARD_DIM; col_ind++ )
            {
                // "empty" spaces have periods, skip this iteration
                if ( board[ row_ind ][ col_ind ] == '.' )
                {
                    continue;
                }

                // Convert the character to a valid index (numbers are [1,9], want [0,8] to fit in board dimensions)
                size_t val_indx = board[ row_ind ][ col_ind ] - static_cast<int>( '0' ) - 1;

                // Calculation to figure out which 3x3 square we're currently in
                size_t square_ind = ( row_ind / 3 ) * 3 + ( col_ind / 3 );

                // If that number has been logged in that row, column, or square - return false (invalid sudoku)
                if ( in_row[ row_ind ][ val_indx ] || in_column[ col_ind ][ val_indx ] || in_square[ square_ind ][ val_indx ] )
                {
                    return false;
                }
                else
                {
                    // Set flags in specific indexes to log this number
                    in_row[ row_ind ][ val_indx ] = true;
                    in_column[ col_ind ][ val_indx ] = true;
                    in_square[ square_ind ][ val_indx ] = true;
                }
            } // end of column for loop
        } // end of row for loop
        
        // Made it through the entire Sudoku
        return true;
    } // end of isValidSudoku
}; // end of Solution Class