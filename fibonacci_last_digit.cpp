#include <iostream>
//#include <cassert>

/*int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous % 10;
        previous = current % 10;
        current = tmp_previous + current;
    }

    return current % 10;
}*/

int get_fibonacci_last_digit_fast(int a)
{
	if (a <= 1)
		return a;
	else
	{
		int first = 0;
		int second = 1;
		int next = 0;
		for (int i = 2; i <= a; i++)
		{
			next = first + second;
			first = second %10;
			second = next % 10;
		}
		return next % 10;
	}
}

int main() {

	/*while (true)
	{
		int n = rand() % 10000000;
		int n1 = get_fibonacci_last_digit_naive(n);
		int n2 = get_fibonacci_last_digit_fast(n);
		std::cout << n << " " << n1 << " " << n2 << "\n";
		assert((n1 == n2), "different");

	}*/
    int n;
    std::cin >> n;
	std::cout << get_fibonacci_last_digit_fast(n);
	return 0;
    }
