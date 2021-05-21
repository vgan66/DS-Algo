#include <iostream>
#include <vector>
//#include <cassert>

int get_change(int m) {
  //write your code here
	std::vector<int> v{ 10,5,1 };
	int n = 0;
	for (auto i : v)
	{
		if (m > 0)
		{
			n += m / i;
			m = m % i;
		}
	}	
  return n;
}

int main() {

	/*int count = 0;
	while (count < 50)
	{
		
		int m = rand() % 1000 + 1;
		std::cout << m << " ";
		std::cout << get_change(m) << '\n';
		count++;
  }
	assert(count != 50);*/
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
