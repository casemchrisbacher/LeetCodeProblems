class FizzBuzz {
private:
    int n;
    std::atomic <int> mAtomicInt{1};

public:
    FizzBuzz(int n) {
        this->n = n;
    }

    // printFizz() outputs "fizz".
    void fizz(function<void()> printFizz) {
        while ( mAtomicInt <= n )
        {
            if ( mAtomicInt % 3 == 0 && mAtomicInt % 5 != 0 )
            {
                printFizz();
                mAtomicInt += 1;
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }

    // printBuzz() outputs "buzz".
    void buzz(function<void()> printBuzz) {
        while ( mAtomicInt <= n )
        {
            if ( mAtomicInt % 3 != 0 && mAtomicInt % 5 == 0 )
            {
                printBuzz();
                mAtomicInt += 1;
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }

    // printFizzBuzz() outputs "fizzbuzz".
	void fizzbuzz(function<void()> printFizzBuzz) {
        while ( mAtomicInt <= n )
        {
            if ( mAtomicInt % 15 == 0 )
            {
                printFizzBuzz();
                mAtomicInt += 1;
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }

    // printNumber(x) outputs "x", where x is an integer.
    void number(function<void(int)> printNumber) {
        while ( mAtomicInt <= n )
        {
            if ( mAtomicInt % 3 != 0 && mAtomicInt % 5 != 0 )
            {
                printNumber( mAtomicInt );
                mAtomicInt += 1;
            }
            else
            {
                std::this_thread::yield();
            }
        }
    }
};