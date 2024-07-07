class FizzBuzz {
private:
    int n;
    int counter{1};
    std::mutex mtx;

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while ( counter <= n )
        {
            std::unique_lock<std::mutex> lock( mtx );
            if ( counter > n ) return;
            if ( counter % 3 == 0 && counter % 5 != 0 )
            {
                printFizz();
                counter++;
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while ( counter <= n )
        {
            std::unique_lock<std::mutex> lock( mtx );
            if ( counter > n ) return;
            if ( counter % 3 != 0 && counter % 5 == 0 )
            {
                printBuzz();
                counter++;
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while ( counter <= n )
        {
            std::unique_lock<std::mutex> lock( mtx );
            if ( counter > n ) return;
            if ( counter % 15 == 0 )
            {
                printFizzBuzz();
                counter++;
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while ( counter <= n )
        {
            std::unique_lock<std::mutex> lock( mtx );
            if ( counter > n ) return;
            if ( counter % 3 != 0 && counter % 5 != 0 )
            {
                printNumber(counter);
                counter++;
            }
        }
    }
};