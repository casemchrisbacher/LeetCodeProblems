class Solution {
private:
    void dfs(vector<vector<char>>& board, std::set<std::pair<int, int>>& coords, int y, int x )
    {
        if ( x < 0 || y < 0 || y >= board.size() || x >= board[0].size() || 
            coords.count({y,x}) || board[y][x] == 'X' ) return;
        coords.insert({y,x});

        dfs( board, coords, y + 1, x );
        dfs( board, coords, y - 1, x );
        dfs( board, coords, y, x + 1 );
        dfs( board, coords, y, x - 1 );
    }
public:
    void solve(vector<vector<char>>& board) 
    {
        std::set<std::pair<int, int>> coords;
        const int HEIGHT = board.size();
        const int WIDTH = board[0].size();
        for ( int y = 0; y < HEIGHT; y++ )
        {
            if ( board[y][0] == 'O' )
            {
                dfs( board, coords, y, 0 );
            }
            if ( board[y][WIDTH-1] == 'O' )
            {
                dfs( board, coords, y, WIDTH-1 );
            }

        }
        for ( int x = 0; x < WIDTH; x++ )
        {
            if ( board[0][x] == 'O' )
            {
                dfs( board, coords, 0, x );
            }
            if ( board[HEIGHT-1][x] == 'O' )
            {
                dfs( board, coords, HEIGHT-1, x );
            }
        }
        board = std::vector<std::vector<char>>( board.size(), std::vector<char>( board[0].size(), 'X' ) );

        for ( const auto& coord : coords )
        {
            board[ coord.first ][ coord.second ] = 'O';
        }
    }
};