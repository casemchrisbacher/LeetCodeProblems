class FooBar {
private:
    int n;
    std::mutex mMutex;
    std::condition_variable mCondVar;
    bool mFoo;

public:
    FooBar(int n) {
        this->n = n;
        this->mFoo = true;
    } // end of constructor

    void foo( function<void()> printFoo )
    {
        
        for (int i = 0; i < n; i++) {
            // instatiate lock every loop
            std::unique_lock uniq_lck( mMutex );

            // wait until foo is set to true, time to write foo
            mCondVar.wait( uniq_lck, [&](){ return mFoo; } );

        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();

            // set mFoo to false, time to write bar
            mFoo = false;

            // notify one thread (the only other one)
            mCondVar.notify_one();
        }
    } // end of foo

    void bar( function<void()> printBar )
    {
        for ( int i = 0; i < n; i++ ) {
             // instatiate lock every loop
            std::unique_lock uniq_lck( mMutex );

            // wait until foo is set to false, time to write bar (not foo)
            mCondVar.wait( uniq_lck, [&](){ return !mFoo; } );

        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            
            // set mFoo to true again, write foo next
            mFoo = true;

            // notify one thread it can go next (foo thread)
            mCondVar.notify_one();
        }
    } // end of bar
}; // end of FooBar class