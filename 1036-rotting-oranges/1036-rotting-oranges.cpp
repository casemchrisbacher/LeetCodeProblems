class Solution {
public:
    int orangesRotting( vector<vector<int>>& grid )
    {
        std::queue<std::pair<int, int>> q;
        int fresh{ 0 };
        for ( int i = 0; i < grid.size(); i++ )
        {
            for ( int j = 0; j < grid[ 0 ].size(); j++ )
            {
                if ( grid[ i ][ j ] == 2 )
                {
                    q.push( { i, j } );
                }
                if ( grid[ i ][ j ] == 1 )
                {
                    fresh++;
                }

            }
        }

        if ( q.empty() && fresh == 0 ) return 0;
        else if ( q.empty() ) return -1;

        std::vector<int> DX{ 1, -1, 0, 0 };
        std::vector<int> DY{ 0, 0, 1, -1 };
        int num_minutes{ -1 };
        while ( !q.empty() )
        {
            int Q_SIZE = q.size();
            num_minutes++;
            for ( int k = 0; k < Q_SIZE; k++ )
            {
                std::pair<int, int> coords = q.front();
                q.pop();
                for ( int i = 0; i < 4; i++ )
                {
                    int new_x = coords.first + DX[ i ];
                    int new_y = coords.second + DY[ i ];

                    if ( new_x >= 0 && new_y >= 0 && new_x < grid.size() && new_y < grid[ 0 ].size() && grid[ new_x ][ new_y ] == 1 )
                    {
                        q.push( { new_x, new_y } );
                        grid[ new_x ][ new_y ]++;
                        fresh--;
                    }
                }
            }
        }
        if ( fresh != 0 ) return -1;
        return num_minutes;
        
    }
};