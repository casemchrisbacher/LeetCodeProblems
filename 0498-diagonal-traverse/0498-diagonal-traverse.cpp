class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) 
    {
        int row_ind{0};
        int col_ind{0};
        bool up{true};
        const int MAX_ROW = mat.size() - 1;
        const int MAX_COL = mat[0].size() - 1;
        std::vector<int> diag;

        while ( row_ind <= MAX_ROW && col_ind <= MAX_COL )
        {
            diag.push_back( mat[row_ind][col_ind] );
            if ( up )
            {
                if ( row_ind == 0 && col_ind != MAX_COL )
                {
                    col_ind++;
                    up = false;
                }
                else if ( col_ind == MAX_COL )
                {
                    row_ind++;
                    up = false;
                }
                else
                {
                    col_ind++;
                    row_ind--;
                }
            }
            else
            {
                if ( col_ind == 0 && row_ind != MAX_ROW )
                {
                    row_ind++;
                    up = true;
                }
                else if ( row_ind == MAX_ROW )
                {
                    col_ind++;
                    up = true;
                }
                else
                {
                    col_ind--;
                    row_ind++;
                }
            }
        }
        return diag;
    }
};