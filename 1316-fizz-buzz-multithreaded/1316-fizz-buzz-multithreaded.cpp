class FizzBuzz {
private:
    int n;
    int counter{1};
    std::mutex mtx;
    std::condition_variable mCondVar;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while ( counter <= n )
        {
            std::unique_lock<std::mutex> lock( mtx );

            mCondVar.wait( lock, [ this ](){ return ( counter % 3 == 0 && counter % 5 != 0 ) || counter > n; } );
            if ( counter > n ) return;
            
            printFizz();
            counter++;
            mCondVar.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while ( counter <= n )
        {
            std::unique_lock<std::mutex> lock( mtx );

            mCondVar.wait( lock, [ this ](){ return ( counter % 3 != 0 && counter % 5 == 0 ) || counter > n; } );
            if ( counter > n ) return;
            
            printBuzz();
            counter++;
            mCondVar.notify_all();
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while ( counter <= n )
        {
            std::unique_lock<std::mutex> lock( mtx );

            mCondVar.wait( lock, [ this ](){ return ( counter % 15 == 0 ) || counter > n; } );
            if ( counter > n ) return;
            
            printFizzBuzz();
            counter++;
            mCondVar.notify_all();
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while ( counter <= n )
        {
            std::unique_lock<std::mutex> lock( mtx );

            mCondVar.wait( lock, [ this ](){ return ( counter % 3 != 0 && counter % 5 != 0 ) || counter > n; } );
            if ( counter > n ) return;
            
            printNumber( counter );
            counter++;
            mCondVar.notify_all();
        }
    }
};