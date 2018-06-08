#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_sum_last_digit_fast(long long from, long long n)  {
     if (n <= 1)
        return n;
	long long sum = 1;
    int previous = 0;
    int current  = 1;
    
    for (long long i = 0; i < n-1 ; ++i) {
        int result = previous + current;
        previous = current;
        if(result >10)
        	result = result % 10;
        current = result;
        if(i>from)
        sum = sum + result;
        
    }

    return sum % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
