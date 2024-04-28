// ***************************************************************
//
// Mutex implementation, multi core processor
//
// ***************************************************************
class FizzBuzz {
public:
    FizzBuzz( int n ) 
    {
        this->n = n;
        this->mCurrNum = 1;
    }

    // printFizz() outputs "fizz".
    void fizz( function<void()> printFizz ) 
    {
        while ( true ) 
        {
            unique_lock<mutex> lock( mMutex );
            mCondVar.wait( lock, [ & ]{ return ( mCurrNum % 3 == 0 && mCurrNum % 5 != 0) || mCurrNum > n; } );
            if ( mCurrNum > n ) return;
            printFizz();
            ++mCurrNum;
            mCondVar.notify_all();
        }
    } // end of fizz

    // printBuzz() outputs "buzz".
    void buzz( function<void()> printBuzz ) 
    {
        while ( true ) 
        {
            unique_lock<mutex> lock( mMutex );
            mCondVar.wait( lock, [ & ]{ return ( mCurrNum % 3 != 0 && mCurrNum % 5 == 0) || mCurrNum > n; } );
            if ( mCurrNum > n ) return;
            printBuzz();
            ++mCurrNum;
            mCondVar.notify_all();
        }
    } // end of buzz

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz( function<void()> printFizzBuzz ) 
    {
        while ( true ) 
        {
            unique_lock<mutex> lock( mMutex );
            mCondVar.wait( lock, [ & ]{ return ( mCurrNum % 3 == 0 && mCurrNum % 5 == 0) || mCurrNum > n; } );
            if ( mCurrNum > n ) return;
            printFizzBuzz();
            ++mCurrNum;
            mCondVar.notify_all();
        }
    } // end of fizzbuzz

    // printNumber(x) outputs "x", where x is an integer.
    void number( function<void( int )> printNumber ) 
    {
        while ( true ) 
        {
            unique_lock<mutex> lock( mMutex );
            mCondVar.wait( lock, [ & ]{ return ( mCurrNum % 3 != 0 && mCurrNum % 5 != 0) || mCurrNum > n; } );
            if ( mCurrNum > n ) return;
            printNumber( mCurrNum );
            ++mCurrNum;
            mCondVar.notify_all();
        }
    } // end of number

private:
    int n;
    int mCurrNum;
    std::condition_variable mCondVar;
    std::mutex mMutex;
}; // end of Solution class

// ***************************************************************
//
// Atomic integer implementation, single core processor
//
// ***************************************************************
// class FizzBuzz {
// private:
//     int n;
//     std::atomic <int> mAtomicInt{1};

// public:
//     FizzBuzz( int n ) {
//         this->n = n;
//     }

//     // printFizz() outputs "fizz".
//     void fizz( function<void()> printFizz ) {
//         // Printing different outputs from 1 to n
//         while ( mAtomicInt <= n )
//         {
//             if ( mAtomicInt % 3 == 0 && mAtomicInt % 5 != 0 )
//             {
//                 printFizz();
//                 mAtomicInt++;
//             }
//             else
//             {
//                 // Want atomic
//                 std::this_thread::yield();
//             }
//         }
//     } // end of fizz

//     // printBuzz() outputs "buzz".
//     void buzz( function<void()> printBuzz ) {
//         while ( mAtomicInt <= n )
//         {
//             if ( mAtomicInt % 3 != 0 && mAtomicInt % 5 == 0 )
//             {
//                 printBuzz();
//                 mAtomicInt++;
//             }
//             else
//             {
//                 std::this_thread::yield();
//             }
//         }
//     } // end of buzz

//     // printFizzBuzz() outputs "fizzbuzz".
// 	void fizzbuzz( function<void()> printFizzBuzz ) {
//         while ( mAtomicInt <= n )
//         {
//             if ( mAtomicInt % 15 == 0 )
//             {
//                 printFizzBuzz();
//                 mAtomicInt++;
//             }
//             else
//             {
//                 std::this_thread::yield();
//             }
//         }
//     } // end of fizzbuzz

//     // printNumber(x) outputs "x", where x is an integer.
//     void number( function<void( int )> printNumber ) 
//     {
//         while ( mAtomicInt <= n )
//         {
//             if ( mAtomicInt % 3 != 0 && mAtomicInt % 5 != 0 )
//             {
//                 printNumber( mAtomicInt );
//                 mAtomicInt++;
//             }
//             else
//             {
//                 std::this_thread::yield();
//             }
//         }
//     } // end of number
// }; // end of Solution class