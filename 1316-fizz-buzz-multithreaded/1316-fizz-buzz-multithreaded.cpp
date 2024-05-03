class FizzBuzz {
private:
    // Value to count up to
    int n;

    // Count up until mCounter == n [1,n]
    int mCounter{1};

    // Mutex for individual threads to grab when entering critical sections
    std::mutex mMutex;

    // Use this to wait until it's this threads turn
    std::condition_variable mCondVar;

public:
    FizzBuzz(int n) {
        this->n = n;
    } // end of FizzBuzz parameterized constructor

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        // loop through the range to be printed [1,n]
        while ( true )
        {
            // this thread grabs the mutex
            std::unique_lock<std::mutex> unq_lock( mMutex );
            
            // Wait here until mCounter is divisible by 3 and not 5
            mCondVar.wait( unq_lock, [ this ](){ return ( mCounter % 3 == 0 && mCounter % 5 != 0 ) || mCounter > n; } );

            // Don't print if we're already past the final print
            if ( mCounter > n ) return;

            // Output "fizz" - condition satisfied
            printFizz();

            // Increment counter before exiting critical section
            mCounter++;

            // Notify condition variable to check the lambda function again
            mCondVar.notify_all();

        } // end of infinite loop
        
    } // end of fizz

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {

        // loop through the range to be printed [1,n]
        while ( true )
        {
            // this thread grabs the mutex
            std::unique_lock<std::mutex> unq_lock( mMutex );
            
            // Wait here until mCounter is divisible by 5 and not 3
            mCondVar.wait( unq_lock, [ this ](){ return ( mCounter % 3 != 0 && mCounter % 5 == 0 ) || mCounter > n; } );

            // Don't print if we're already past the final print
            if ( mCounter > n ) return;

            // Output "buzz" - condition satisfied
            printBuzz();

            // Increment counter before exiting critical section
            mCounter++;

            // Notify condition variable to check the lambda function again
            mCondVar.notify_all();

        } // end of infinite loop
    } // end of buzz

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        // loop through the range to be printed [1,n]
        while ( true )
        {
            // this thread grabs the mutex
            std::unique_lock<std::mutex> unq_lock( mMutex );
            
            // Wait here until mCounter is divisible by 3 and 5
            mCondVar.wait( unq_lock, [ this ](){ return ( mCounter % 3 == 0 && mCounter % 5 == 0 ) || mCounter > n; } );

            // Don't print if we're already past the final print
            if ( mCounter > n ) return;

            // Output "fizzbuzz" - condition satisfied
            printFizzBuzz();

            // Increment counter before exiting critical section
            mCounter++;

            // Notify condition variable to check the lambda function again
            mCondVar.notify_all();

        } // end of infinite loop
        
    } // end of fizzbuzz

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        // loop through the range to be printed [1,n]
        while ( true )
        {
            // this thread grabs the mutex
            std::unique_lock<std::mutex> unq_lock( mMutex );
            
            // Wait here until mCounter is not divisible by 3 or 5
            mCondVar.wait( unq_lock, [ this ](){ return ( mCounter % 3 != 0 && mCounter % 5 != 0 ) || mCounter > n; } );

            // Don't print if we're already past the final print
            if ( mCounter > n ) return;

            // Output the number - condition satisfied
            printNumber( mCounter );

            // Increment counter before exiting critical section
            mCounter++;

            // Notify condition variable to check the lambda function again
            mCondVar.notify_all();

        } // end of infinite loop
    }
}; // end of FizzBuzz class