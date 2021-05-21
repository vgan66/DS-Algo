#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
	vector<vector<int>>values((int)w.size(), vector<int>(W + 1, 0));

	for (int i = 1; i < (int)w.size(); ++i)
	{
		for (int j = 1; j <= W; ++j)
		{
			values[i][j] = values[i - 1][j];
			if (w[i] <= j)
			{
				int val = values[i - 1][j - w[i]] + w[i];
				if (val > values[i][j])
					values[i][j] = val;
			}
		}
	}
  /*int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;*/

	return values[(int)w.size() -1].back();
}

int main() {
	/*while (true)
	{*/
		int n, W;
		std::cin >> W >> n;
		vector<int> w(n + 1);
		for (int i = 1; i <= n; i++) {
			std::cin >> w[i];
		}
		std::cout << optimal_weight(W, w) << '\n';
	/*}*/
}
