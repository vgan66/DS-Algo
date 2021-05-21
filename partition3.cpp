#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using std::vector;

int partition3(vector<int> &A) {

	int sum = std::accumulate(A.begin(), A.end(), 0);
	if (sum % 3 != 0)
		return 0;
	int W = sum / 3;

	vector<vector<int>> v((int)A.size() + 1, vector<int>(W + 1, 0));
	int c = 0;
	for (int i = 1; i <= (int)A.size(); ++i)
	{
		for (int w = 1; w <= W; ++w)
		{
			v[i][w] = v[i - 1][w];
			if (A[i-1] <= w)
			{
				int val = v[i - 1][w - A[i-1]] + A[i - 1];
				if (val > v[i][w])
					v[i][w] = val;
			}
		}
		if (v[i][W] == W)
		{
			++c;
			int k = W;
			for (int j = i - 1; j >= 0; --j)
			{
				if (k >= A[j] && v[j][k - A[j]] + A[j]  == k)
				{
					k = v[j][k - A[j]];
					A[j] = 0;
				}
				else
				{
					k = v[j][k];
				}
			}

			for (int j = 0; j < A.size() + 1; ++j)
			{
				for (int k = 0; k < W + 1; ++k)
				{
					v[j][k] = 0;
				}
			}
			i = 0;
			//A[i - 1] = 0;
		}
	}
	if (c == 3)
		return 1;
  //write your code here
  return 0;
}

int main() {
	while (true)
	{
		int n;
		std::cin >> n;
		vector<int> A(n);
		for (size_t i = 0; i < A.size(); ++i) {
			std::cin >> A[i];
		}
		std::cout << partition3(A) << '\n';
	}
}
