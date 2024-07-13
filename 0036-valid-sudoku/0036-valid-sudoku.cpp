class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        std::vector<std::unordered_set<char>> squares( 9, std::unordered_set<char>() );
        std::vector<std::unordered_set<char>> rows( 9, std::unordered_set<char>() );
        std::vector<std::unordered_set<char>> cols( 9, std::unordered_set<char>() );

        for ( int row_ind = 0; row_ind < board.size(); row_ind++ )
        {
            for ( int col_ind = 0; col_ind < board[0].size(); col_ind++ )
            {
                if ( board[row_ind][col_ind] == '.' ) continue;
                if ( rows[row_ind].count( board[row_ind][col_ind] ) || 
                    cols[col_ind].count( board[row_ind][col_ind] ) || 
                    squares[ ((row_ind / 3) * 3) + (col_ind / 3) ].count( board[row_ind][col_ind] ) )
                {
                    return false;
                }
                else
                {
                    rows[row_ind].insert( board[row_ind][col_ind] );
                    cols[col_ind].insert( board[row_ind][col_ind] );
                    squares[ ((row_ind / 3) * 3) + (col_ind / 3) ].insert( board[row_ind][col_ind] );
                }
            }
        }
        return true;
    }
};