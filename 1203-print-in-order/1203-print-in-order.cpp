class Foo {
private:
    std::mutex mMutex;
    std::condition_variable mCondVar;
    int mFunctionCnt;

public:
    Foo() {
        this->mFunctionCnt = 1;
    }

    void first( function<void()> printFirst ) 
    {
        // create a unique lock to allow for waiting
        std::unique_lock unq_lck( mMutex );

        // wait with conditional variable, go past if count is equal to this function
        mCondVar.wait( unq_lck, [ & ](){ return ( mFunctionCnt == 1 ); } );

        // increment mFunctionCnt so that next function prints next
        ++mFunctionCnt;

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();

        // notify the other threads that they should check lambda function again
        mCondVar.notify_all();
    } // end of first

    void second( function<void()> printSecond ) 
    {
        // create a unique lock to allow for waiting
        std::unique_lock unq_lck( mMutex );

        // Wait with conditional variable, go past if count is equal to this function
        mCondVar.wait( unq_lck, [ & ](){ return ( mFunctionCnt == 2 ); } );
        
        // increment mFunctionCnt so that next function prints next
        ++mFunctionCnt;

        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();

        // notify the other threads that they should check lambda function again
        mCondVar.notify_all();
    } // end of second

    void third( function<void()> printThird ) 
    {
        // create a unique lock to allow for waiting
        std::unique_lock unq_lck( mMutex );

        // Wait with conditional variable, go past if count is equal to this function
        mCondVar.wait( unq_lck, [ & ](){ return ( mFunctionCnt == 3 ); } );

        // increment mFunctionCnt so that next function prints next
        ++mFunctionCnt;
        
        // printThird() outputs "third". Do not change or remove this line.
        printThird();

        // notify the other threads that they should check lambda function again
        mCondVar.notify_all();
    } // end of third

};