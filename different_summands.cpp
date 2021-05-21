#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int i = 1;
  while (n != 0)
  {
	  summands.push_back(i);
	  if (std::find(std::begin(summands), std::end(summands), n - i) != std::end(summands))
		  summands.pop_back();
	  else
		  n = n - i;
	  ++i;
  }
  return summands;
}

int main() {
		int n;
		std::cin >> n;
		vector<int> summands = optimal_summands(n);
		std::cout << summands.size() << '\n';
		for (size_t i = 0; i < summands.size(); ++i) {
			std::cout << summands[i] << ' ';
		}
}
