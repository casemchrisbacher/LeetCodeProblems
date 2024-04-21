class ZeroEvenOdd {
private:
    int n;
    std::binary_semaphore mSemEven{ 0 };
    std::binary_semaphore mSemOdd{ 0 };
    std::binary_semaphore mSemZero{ 1 };

public:
    ZeroEvenOdd( int n ) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero( function<void( int )> printNumber ) 
    {
        for ( int inc_ind = 1; inc_ind <= n; inc_ind++ )
        {
            mSemZero.acquire();
            printNumber( 0 );

            if ( inc_ind % 2 == 0 )
            {
                mSemEven.release();
            }
            else
            {
                mSemOdd.release();
            }
        }
        
    } // end of 

    void even( function<void( int )> printNumber ) 
    {
        for ( int inc_ind = 2; inc_ind <= n; inc_ind += 2 )
        {
            mSemEven.acquire();
            printNumber( inc_ind );
            mSemZero.release();
        }
    } // end of 

    void odd( function<void( int )> printNumber ) 
    {
        for ( int inc_ind = 1; inc_ind <= n; inc_ind += 2 )
        {
            mSemOdd.acquire();
            printNumber( inc_ind );
            mSemZero.release();
        }
    } // end of 
}; // end of ZeroEvenOdd class