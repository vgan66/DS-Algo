#include <iostream>
#include <vector>
//#include <cassert>

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = (next + current) % 10;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
	if (to <= 1)
		return to;
	long long period = 2LL;
	std::vector <long long> sum;
	sum.push_back(0LL);
	sum.push_back(1LL);
	long long prev = 0LL;
	long long curr = 1LL;
	for (long long i = 2LL; i <= to; ++i)
	{
		long long next = (prev + curr) % 10;
		prev = curr;
		curr = next;
		if (next == 0 && (prev + curr) == 1)
		{
			break;
		}
		else
		{
			sum.push_back(sum[i - 1] + next);
			++period;
		}
	}
	long long m = to / period;
	long long r = to % period;

	long long s_to = sum[period - 1] * m + sum[r];
	if (from == 0LL)
		return s_to % 10;
	m = (from - 1) / period;
	r = (from - 1) % period;

	long long s_from = sum[period - 1] * m + sum[r];
	return (s_to - s_from) % 10;
}


int main() {
	/*while (true)
	{
	long long m = (rand() % 1000000000);
	long long n = (rand() % 100000000000) + m;
	long long p = get_fibonacci_partial_sum_naive(m, n);
	long long q = get_fibonacci_partial_sum_fast(m, n);
	std::cout << n << " " << m << " " << p << " " << q << "\n";

	assert(p == q);
	}*/
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
	return 0;
}
