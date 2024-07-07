class H2O {
private:
    std::mutex mtx;
    std::condition_variable mCondVar;
    std::atomic <int> mHydroCount{0};
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) 
    {
        std::unique_lock<std::mutex> lock( mtx );

        mCondVar.wait( lock, [this](){ return ( mHydroCount < 2 ); } );
        mHydroCount++;

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        mCondVar.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) 
    {
        std::unique_lock<std::mutex> lock( mtx );

        mCondVar.wait( lock, [this](){ return ( mHydroCount >= 2 ); } );

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        
        mHydroCount = 0;
        mCondVar.notify_all();
        
    }
};