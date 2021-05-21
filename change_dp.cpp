#include <iostream>
#include <limits>
#include <vector>

using namespace std;

int get_change(int m) {
	vector<int> mnc(m + 1);
	vector <int> c{ 1, 3, 4 };
	for (int i = 1; i <= m; ++i)
	{
		mnc[i] = numeric_limits<int>::max();
		for (int j = 0; j < c.size(); ++j)
		{
			if (i >= c[j])
			{
				int numcoins = mnc[i - c[j]] + 1;
				if (numcoins < mnc[i])
					mnc[i] = numcoins;
			}
		}
	}
	return mnc[m];
}

int main() {
	/*while (true)
	{*/
		int m;
		std::cin >> m;
		std::cout << get_change(m) << '\n';
	/*}*/
}
