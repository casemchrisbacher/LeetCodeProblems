class Solution {
public:
    void sortColors( vector<int>& nums )
    {
        int one_cnt{ 0 };
        int left{ 0 };
        int right = nums.size() - 1;

        for ( int ind = 0; ind <= right; ind++ )
        {
            while ( nums[ right ] == 2 )
            {
                right--;
                if ( ind > right )
                {
                    for ( int i = 0; i < one_cnt; i++ )
                    {
                        nums [ left + i ] = 1;
                    }
                    return;
                }
            }
            switch( nums[ ind ] )
            {
                case 0:
                    nums[ left++ ] = 0;
                    break;
                case 1:
                    one_cnt++;
                    break;
                case 2:
                    if ( nums[ right ] == 0 )
                    {
                        nums[ left++ ] = 0;
                        nums[ right-- ] = 2;
                    }
                    else
                    {
                        one_cnt++;
                        nums[ right-- ] = 2;
                    }
                    break;
            }
        }
        for ( int i = 0; i < one_cnt; i++ )
        {
            nums [ left + i ] = 1;
        }
    }
};