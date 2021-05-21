#include <iostream>
#include <vector>
//#include <cassert>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += current * current;
    }
    return sum % 10;
}

long long fibonacci_sum_squares_fast(long long n) {
	if (n <= 1)
		return n;
	long long period = 2LL;
	std::vector <long long> sum;
	sum.push_back(0LL);
	sum.push_back(1LL);
	long long prev = 0LL;
	long long curr = 1LL;
	for (long long i = 2LL; i <= n; ++i)
	{
		long long next = (prev + curr)% 10;
		prev = curr;
		curr = next;
		if (next == 0 && (prev + curr) == 1)
		{
			break;
		}
		else
		{
			sum.push_back(sum[i - 1] + (next*next));
			++period;
		}
	}
	long long m = n / period;
	long long r = n % period;

	long long s = sum[period - 1] * m + sum[r];
	return s % 10;;
}

int main() {
	/*while (true)
	{
	long long n = (rand() % 100000000000);
	long long p = fibonacci_sum_squares_naive(n);
	long long q = fibonacci_sum_squares_fast(n);
	std::cout << n << " " << p << " " << q << "\n";

	assert(p == q);
	}*/
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
	return 0;
}
