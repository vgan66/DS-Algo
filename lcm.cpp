#include <iostream>
#include <algorithm>
//#include <cstdlib>
//#include <cassert>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {
	if (std::max(a, b) == a)
	{
		for (long long l = a; l <= (long long)a * b; l = l + a)
			if (l % b == 0)
				return l;
	}
	else
	{
		for (long long l = b; l <= (long long)a * b; l = l + b)
			if (l % a == 0)
				return l;
	}
}

int main() {
	/*while (true)
	{
		long long a = rand() % 10000000;
		long long b = rand() % 10000000;
		long long p = lcm_naive(a, b);
		long long q = lcm_fast(a, b);
		std::cout << p << " " << q << "\n";
		assert(p == q);
    }*/
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
