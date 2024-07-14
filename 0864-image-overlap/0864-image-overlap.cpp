class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        std::set<std::pair<int, int>> img1_coords;
        std::set<std::pair<int, int>> img2_coords;
        const int SIZE = img1.size();

        for ( int y = 0; y < SIZE; y++ )
        {
            for( int x = 0; x < SIZE; x++ )
            {
                if ( img1[y][x] == 1 )
                {
                    img1_coords.insert({y,x});
                }
                if ( img2[y][x] == 1 )
                {
                    img2_coords.insert({y,x});
                }
            }
        }

        int max{0};
        std::set<std::pair<int,int>> translations;
        for ( auto& img1_coord : img1_coords )
        {
            for ( auto& img2_coord : img2_coords )
            {
                int y_diff = img2_coord.first - img1_coord.first;
                int x_diff = img2_coord.second - img1_coord.second;
                if ( translations.count({y_diff, x_diff}) ) continue;
                else
                {
                    int overlap{0};
                    for ( auto& start : img1_coords )
                    {
                        if ( img2_coords.count( {start.first + y_diff, start.second + x_diff } ) )
                        {
                            overlap++;
                        }
                    }
                    max = std::max(max, overlap);
                    translations.insert({y_diff, x_diff});
                }

            }
        }
        return max;
    }
};