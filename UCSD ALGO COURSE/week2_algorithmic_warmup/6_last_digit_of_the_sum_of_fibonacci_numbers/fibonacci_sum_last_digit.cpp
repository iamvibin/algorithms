#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

long long get_fibonacci_sum_last_digit_fast(long long n)  {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
	long long sum = 1;
    for (long long i = 0; i < n-1 ; ++i) {
        int result = previous + current;
        previous = current;
        if(result >10)
        	result = result % 10;
        current = result;
        sum = sum + result;
        
    }

    return sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << get_fibonacci_sum_last_digit_fast(n);
}
