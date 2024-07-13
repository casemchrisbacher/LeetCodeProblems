class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        std::vector<std::pair<int, int>> inds;
        for ( int y = 0; y < matrix.size(); y++ )
        {
            for ( int x = 0; x < matrix[0].size(); x++ )
            {
                if ( matrix[y][x] == 0 )
                {
                    inds.push_back({y, x});
                }
            }
        }
        for ( int i = 0; i < inds.size(); i++ )
        {
            for ( int y = 0; y < matrix.size(); y++ )
            {
                matrix[y][inds[i].second] = 0;
            }
            for ( int x = 0; x < matrix[0].size(); x++ )
            {
                matrix[inds[i].first][x] = 0;
            }
        }
    }
};