class Solution {
private:
    void floodFillHelp(vector<vector<int>>& image, int sr, int sc, const int color, const int startColor )
    {
        if ( sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] == color || image[sr][sc] != startColor ) return;
        image[sr][sc] = color;
        floodFillHelp( image, sr + 1, sc, color, startColor );
        floodFillHelp( image, sr - 1, sc, color, startColor );
        floodFillHelp( image, sr, sc + 1, color, startColor );
        floodFillHelp( image, sr, sc - 1, color, startColor );
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        floodFillHelp( image, sr, sc, color, image[sr][sc] );
        return image;
    }
};