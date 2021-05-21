#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using std::vector;
using std::string;

bool isgreatororqual(string x, string y) {
	string xy = x.append(y);
	string yx = y.append(x);

	return xy.compare(yx) > 0;
}



string largest_number(vector<string> a) {
  string res;
 std::sort(std::begin(a), std::end(a), isgreatororqual);
 for (auto i : a)
	  res.append(i);
  return res;
}

string largest_number_2(vector<string> a)
{
	string res;
	auto it = std::max_element(std::begin(a), std::end(a));
	int max_len = it->length() + 1;
	std::sort(std::begin(a), std::end(a), [max_len](string a, string b) {
		while (a.length() < max_len)
			a.append(a);
		if (a.length() > max_len)
			a = a.substr(0, max_len);
		while (b.length() < max_len)
			b.append(b);
		if (b.length() > max_len)
			b = b.substr(0, max_len);

		return a.compare(b) > 0;
	});

	for (auto i : a)
		res.append(i);
	return res;

}

int main() {
		int n;
		std::cin >> n;
		vector<string> a(n);
		for (size_t i = 0; i < a.size(); i++) {
			std::cin >> a[i];
		}
		std::cout << largest_number(a) << " ";
		std::cout << largest_number_2(a);

		return 0;
}
