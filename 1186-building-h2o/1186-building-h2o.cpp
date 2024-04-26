class H2O {
    std::atomic <int> mNumHydro{ 0 };

    std::mutex mMutex;
    std::condition_variable mReadyForPrint;
public:
    H2O() {
        mNumHydro = 0;
    } // end of H2O constructor

    void hydrogen( function<void()> releaseHydrogen )
    {
        // Create a lock for the condition variable wait
        std::unique_lock uniq_lck( mMutex );

        // wait on two H's and one O to be inputted (through checking atomic vars)
        mReadyForPrint.wait( uniq_lck, [ & ](){ return ( mNumHydro < 2 ); } );

        // increment the atomic int for hydro to know it's been called
        ++mNumHydro;

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();

        // notify all of the other threads to run the lambda function again
        mReadyForPrint.notify_all();

    } // end of hydrogen

    void oxygen( function<void()> releaseOxygen )
    {
        // Create a lock for the condition variable wait
        std::unique_lock uniq_lck( mMutex );

        // wait on two H's and one O to be inputted (through checking atomic vars)
        mReadyForPrint.wait( uniq_lck, [ & ](){ return ( mNumHydro >= 2 ); } );
        
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();

        // reset the hydrogen count to 0
        mNumHydro = 0;

        // notify all of the other threads to run the lambda function again
        mReadyForPrint.notify_all();

    } // end of oxygen
}; // end of H2O class