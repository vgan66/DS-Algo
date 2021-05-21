#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>


double get_optimal_value(int capacity, std::vector<int> weights, std::vector<int> values) {
  double value = 0.0;
  std::vector<std::pair<double, int>> puv;
  for (auto i = 0; i < weights.size(); ++i)
	  puv.push_back(std::make_pair((double)values[i] / (double)weights[i], weights[i]));

  std::sort(std::begin(puv), std::end(puv), [](std::pair<double, int> a, std::pair<double, int> b) {
	  return a.first > b.first; });

  for(auto i : puv)
  {
	  if (capacity <= i.second)
	  {
		  value += (double)capacity * i.first;
		  break;
	  }
	  value += (double)i.second * i.first;
	  capacity = capacity - i.second;
  }
  return value;
}

int main() {
		int n;
		int capacity;
		std::cin >> n >> capacity;
		std::vector<int> values(n);
		std::vector<int> weights(n);
		for (int i = 0; i < n; i++) {
			std::cin >> values[i] >> weights[i];
		}
		double optimal_value = get_optimal_value(capacity, weights, values);
		std::cout.precision(10);
		std::cout << optimal_value << std::endl;
  return 0;
}
