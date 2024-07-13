class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) 
    {
        int value{0};
        const int HEIGHT = img.size();
        const int WIDTH = img[0].size();
        std::vector<std::vector<int>> avg( HEIGHT, std::vector<int>( WIDTH,0 ) );

        for( int y = 0; y < HEIGHT; y++ )
        {
            for( int x = 0; x < WIDTH; x++ )
            {
                int counter{0};
                int sum{0};
                for (int i = y-1; i < y + 2; i++ )
                {
                    for ( int j = x-1; j < x + 2; j++ )
                    {
                        if ( i >= 0 && j >= 0 && i < HEIGHT && j < WIDTH )
                        {
                            sum += img[i][j];
                            counter++;
                        }
                    }
                }
                avg[y][x] = sum / counter;

            }
        }
        return avg;
    }
};