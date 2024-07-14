class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) 
    {
        std::vector<std::pair<int, int>> img1_coords;
        std::vector<std::pair<int, int>> img2_coords;
        const int SIZE = img1.size();

        for ( int y = 0; y < SIZE; y++ )
        {
            for( int x = 0; x < SIZE; x++ )
            {
                if ( img1[y][x] == 1 )
                {
                    img1_coords.push_back({y,x});
                }
                if ( img2[y][x] == 1 )
                {
                    img2_coords.push_back({y,x});
                }
            }
        }

        int max{0};
        std::map<std::pair<int,int>, int> overlap;
        for ( const auto& c1 : img1_coords )
        {
            for ( const auto& c2 : img2_coords )
            {
                max = std::max( max, ++overlap[{ c1.first - c2.first, c1.second - c2.second } ] );
            }
        }
        return max;
    }
};