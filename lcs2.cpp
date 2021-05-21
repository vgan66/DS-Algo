#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

int lcs2(vector<int> &a, vector<int> &b) {
	int lcs2 = 0;
	vector<vector<int>> v(a.size() + 1, vector<int>(b.size() + 1, 0));
	for (int i = 1; i <= (int)a.size(); ++i)
		v[i][0] = i;
	for (int j = 1; j <= (int)b.size(); ++j)
		v[0][j] = j;
	for (int i = 1; i <= (int)a.size(); ++i)
	{

		for (int j = 1; j <= (int)b.size(); ++j)
		{
			int in;
			int de;
			int re;
			in = v[i][j - 1] + 1;
			de = v[i - 1][j] + 1;
			int m = min(in, de);
			if (a[i - 1] == b[j - 1])
			{
				re = v[i - 1][j - 1];
				m = min(m, re);
			}
			/*else
				re = v[i - 1][j - 1] + 1;*/
			v[i][j] = m;
			//v[i][j] = min(m, re);
		}
	}
	int i = v.size() - 1;
	int j = v[0].size() - 1;
	while (i > 0  && j > 0)
	{
		if (v[i][j] == v[i][j - 1] + 1)
			j = j - 1;
		else if (v[i][j] == v[i - 1][j] + 1)
			i = i - 1;
		else if (v[i][j] == v[i - 1][j - 1] && a[i - 1] == b[j - 1])
		{
			i = i - 1;
			j = j - 1;
			++lcs2;
		}
		/*else if (v[i][j] == v[i - 1][j - 1] + 1)
		{
			i = i - 1;
			j = j - 1;
		}*/

	}
	return lcs2;
  //return std::min(std::min(a.size(), b.size()), c.size());
}

int main() {
	/*while (true)
	{*/
		size_t n;
		std::cin >> n;
		vector<int> a(n);
		for (size_t i = 0; i < n; i++) {
			std::cin >> a[i];
		}

		size_t m;
		std::cin >> m;
		vector<int> b(m);
		for (size_t i = 0; i < m; i++) {
			std::cin >> b[i];
		}

		std::cout << lcs2(a, b) << std::endl;
	//}
}
