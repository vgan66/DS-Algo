#include <iostream>
#include <vector>
//#include <cstdlib>
//#include <cassert>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous+ current)%m;
    }

    return current;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
	if (n <= 1)
		return n;
	long long period = 2LL;
	std::vector <long long> fib;
	fib.push_back(0LL);
	fib.push_back(1LL);
	for (long long i = 2LL; i <= n; ++i)
	{
		fib.push_back((fib[i-1] + fib[i-2])%m);
		if ((fib[i] == 0) && (fib[i] + fib[i-1]) == 1)
		{
			break;
		}
		else
		{
			++period;
		}
	}
	long long r = n % period;
	return fib[r];
}

int main() {
	/*while (true)
	{
		long long n = (rand() % 100000000000000) + 1;
		long long m = (rand() % 10000000000000) + 2;
		long long p = get_fibonacci_huge_naive(n, m);
		long long q = get_fibonacci_huge_fast(n, m);
		std::cout << n << " " << m << " " << p << " " << q << "\n";

		assert(p == q);
	}*/
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';
	return 0;
}
